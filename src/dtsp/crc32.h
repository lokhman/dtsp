/**
 * File: crc32.h
 *
 * This code is part of Data Transfer Security Protocol (DTSP) library.
 *
 * Optimised ANSI C code for CRC32C Cyclic Redundancy-Check Code.
 *
 * @author Gary S. Brown
 * @author Alexander Lokhman <alex.lokhman@gmail.com>
 *
 * Created on August 2015
 */

#ifndef CRC32_H
#define	CRC32_H

#include <stdint.h>
#include <string.h>

#ifdef	__cplusplus
extern "C" {
#endif

    /**
     * Generate CRC32C checksum.
     *
     * @param buf   Input buffer
     * @param n     Input length
     *
     * @return 32-bit checksum
     */
    uint32_t crc32(const uint8_t *buf, size_t n);

#ifdef	__cplusplus
}
#endif

#endif	/* CRC32_H */
