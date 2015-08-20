/**
 * File: isaac.h
 *
 * This code is part of Data Transfer Security Protocol (DTSP) library.
 *
 * Optimised ANSI C code for ISAAC secure pseudorandom number generator.
 *
 * @author Robert Jenkins <bob_jenkins@burtleburtle.net>
 * @author Alexander Lokhman <alex.lokhman@gmail.com>
 *
 * Created on August 2015
 */

#ifndef ISAAC_H
#define	ISAAC_H

#include <stdint.h>
#include <string.h>

#define ISAAC_SIZE 256U

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct {
        uint16_t n;
        uint32_t a;
        uint32_t b;
        uint32_t c;
        uint32_t r[ISAAC_SIZE];
        uint32_t m[ISAAC_SIZE];
    } isaac_ctx_t;

    /**
     * Seed pseudorandom sequence.
     *
     * @param ctx   ISAAC context
     * @param seed  Seed buffer
     * @param n     Seed length
     *
     * @return void
     */
    void isaac_seed(isaac_ctx_t *ctx, const uint8_t *seed, size_t n);

    /**
     * Generate 32-bit pseudorandom integer.
     *
     * @param ctx   ISAAC context
     *
     * @return 32-bit pseudorandom integer
     */
    uint32_t isaac_rand(isaac_ctx_t *ctx);

#ifdef	__cplusplus
}
#endif

#endif	/* ISAAC_H */

