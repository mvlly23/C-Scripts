#ifndef MURMUR32_H_
#define MURMUR32_H_

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

uint32_t scramble(uint32_t k);
uint32_t murmur3(const void * key, size_t len, uint32_t seed);

#endif //MURMUR32_H_