#pragma once

#include <stdint.h>

/**
 * @brief a method to calculate a buffer's hash (array of unsinged chars)
 *
 * @param crc32c the initial crc value
 * @param buffer the buffer
 * @param length the length of the buffer
 * @return uint32_t the hash of the buffer
 */
uint32_t calculate_crc32c(uint32_t crc32c, const unsigned char *buffer,
                          unsigned int length);