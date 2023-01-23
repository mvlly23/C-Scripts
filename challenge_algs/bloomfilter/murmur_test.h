#ifndef MURMUR32TEST_H_
#define MURMUR32TEST_H_

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

static inline uint32_t murmur_32_scramble(uint32_t k);
uint32_t murmur3_32(const uint8_t* key, size_t len, uint32_t seed);

#endif //MURMUR32TEST_H_ 