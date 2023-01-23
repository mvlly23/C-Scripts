#include "murmur3.h"

//Some guidance from: https://en.wikipedia.org/wiki/MurmurHash & https://github.com/PeterScott/murmur3/blob/master/murmur3.c

// Defining constants
uint32_t c1 = 0xcc9e2d51;
uint32_t c2 = 0x1b873593;
int r1 = 15;
int r2 = 13;
int m = 5;
uint32_t n = 0xe6546b64;

uint32_t scramble(uint32_t k){
    k *= c1;
    k = (k << r1) | (k >> (32 - r1));
    k *= c2;
    return k;
}

uint32_t murmur3(const void * key, size_t len, uint32_t seed){
    uint8_t *data = (uint8_t*)key;
    const int nblocks = len/4;
    uint32_t h = seed;
    uint32_t k;

    //Head
    const uint32_t *blocks = (uint32_t *)(data + (int)len);

    for(int i = -nblocks; i; i++){
        k = blocks[i];
        h ^= scramble(k);
        h = (h << r2) | (h >> (32 - r2));
        h = (h*m) + n;
    }

    //Tail
    for(size_t i = len & 3; i; i--){
        k <<= 8;
        k |= blocks[i - 1];
    }

    scramble(h);
    h ^= len;
    h ^= h >> 16;
    h *= 0x85ebca6b;
	h ^= h >> 13;
	h *= 0xc2b2ae35;
	h ^= h >> 16;

    return h;
}