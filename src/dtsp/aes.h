/**
 * File: aes.h
 *
 * This code is part of Data Transfer Security Protocol (DTSP) library.
 *
 * Optimised ANSI C code for FAST Rijndael/AES CBC cipher.
 *
 * @author Vincent Rijmen <vincent.rijmen@esat.kuleuven.ac.be>
 * @author Antoon Bosselaers <antoon.bosselaers@esat.kuleuven.ac.be>
 * @author Paulo Barreto <paulo.barreto@terra.com.br>
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

#ifndef AES_H
#define	AES_H

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define AES_IV_SIZE 16U
#define AES_KEY_SIZE(b) ((b) / 8)

#ifdef	__cplusplus
extern "C" {
#endif

    typedef enum {
        AES_128 = 128,
        AES_192 = 192,
        AES_256 = 256,
    } aes_bits_t;

    typedef struct {
        aes_bits_t bits;
        uint8_t iv[AES_IV_SIZE];
        uint8_t key[AES_KEY_SIZE(AES_256)];
    } aes_ctx_t;

    /**
     * AES encryption with PKCS7 padding.
     *
     * @param ctx   AES context
     * @param out   Output buffer
     * @param in    Input buffer
     * @param n     Input length
     *
     * @return (N+padding)
     */
    size_t aes_encrypt(aes_ctx_t *ctx, uint8_t *out, const uint8_t *in, size_t n);

    /**
     * AES decryption with truncating padding.
     *
     * @param ctx   AES context
     * @param out   Output buffer
     * @param in    Input buffer
     * @param n     Input length
     *
     * @return (N-padding)
     */
    size_t aes_decrypt(aes_ctx_t *ctx, uint8_t *out, const uint8_t *in, size_t n);

#ifdef	__cplusplus
}
#endif

#endif	/* AES_H */
