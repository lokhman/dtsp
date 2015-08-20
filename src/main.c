/**
 * File: main.c
 *
 * This code is part of Data Transfer Security Protocol (DTSP) library.
 *
 * @author Alexander Lokhman <alex.lokhman@gmail.com>
 *
 * Copyright (c) 2015 Alexander Lokhman
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Created on August 2015
 */

#include <stdio.h>
#include <stdlib.h>

#include "dtsp.h"

int main(int argc, char **argv) {
    dtsp_ctx_t ctx_srv, ctx_cli;
    int i, enc_len1, enc_len2, dec_len1, dec_len2;

    dtsp_buf_t seed = {"Some Random Token", 18};

    dtsp_buf_t udid_srv = {"UDID Server", 12};
    dtsp_buf_t udid_cli = {"UDID Client", 12};

    dtsp_buf_t test1 = {"Alexander Lokhman", 18};
    dtsp_buf_t test2 = {"Linux is freely available, and no one is required "
            "to register their copies with any central authority, so it is "
            "difficult to know how many people use Linux. Several businesses "
            "now survive solely on selling and supporting Linux, and the Linux "
            "newsgroups are some of the most heavily read on the internet, so "
            "the number is likely in the millions, but firm numbers are hard "
            "to come by. The best market research currently indicates between "
            "7.5 and 11 million users.", 462};

    dtsp_init(&ctx_srv, &seed, &udid_srv);
    dtsp_init(&ctx_cli, &seed, &udid_cli);

    uint8_t enc1[test1.n + DTSP_PADDING],
            enc2[test2.n + DTSP_PADDING],
            dec1[2096], dec2[2096];

    enc_len1 = dtsp_encrypt(&ctx_cli, enc1, &test1);
    printf("CLIENT: Encrypt -> %d bytes\n", enc_len1);
    for (i = 0; i < enc_len1; i++) printf("%.2x", enc1[i]);
    printf("\n\n");

    sleep(10);          // consider network timeout

    enc_len2 = dtsp_encrypt(&ctx_cli, enc2, &test2);
    printf("CLIENT: Encrypt -> %d bytes\n", enc_len2);
    for (i = 0; i < enc_len2; i++) printf("%.2x", enc2[i]);
    printf("\n\n");

    sleep(2);           // should decrypt both
    // sleep(5);        // first buffer becomes out of date

    dec_len1 = dtsp_decrypt_bytes(&ctx_srv, dec1, enc1, enc_len1);
    printf("SERVER: Decrypt -> %d bytes\n", dec_len1);
    printf("%s\n\n", dec1);

    // enc2[23] = 42;   // second buffer gets wrong MAC

    dec_len2 = dtsp_decrypt_bytes(&ctx_srv, dec2, enc2, enc_len2);
    printf("SERVER: Decrypt -> %d bytes\n", dec_len2);
    printf("%s\n\n", dec2);

    // these are never decrypted
    dec_len1 = dtsp_decrypt_bytes(&ctx_srv, dec1, enc1, enc_len1);
    printf("SERVER: Decrypt -> %d bytes\n", dec_len1);

    dec_len2 = dtsp_decrypt_bytes(&ctx_srv, dec2, enc2, enc_len2);
    printf("SERVER: Decrypt -> %d bytes\n", dec_len2);

    dtsp_free(&ctx_cli);
    dtsp_free(&ctx_srv);

    return EXIT_SUCCESS;
}

