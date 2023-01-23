#include "murmur3.h"

//Some guidance from: https://en.wikipedia.org/wiki/MurmurHash & https://github.com/PeterScott/murmur3/blob/master/murmur3.c

// Defining constants
uint32_t c1 = 0xcc9e2d51;
uint32_t c2 = 0x1b873593;
int r1 = 15;
int r2 = 13;
int m = 5;
uint32_t n = 0xe6546b64;

uint32_t rotl(uint32_t k, int r){
    return((k << r) | (k >> (32 - r)));
}

uint32_t scramble(uint32_t k){
    k *= c1;
    k = rotl(k, r1);
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
        h = rotl(h, r2);
        h = (h*m) + n;
    }

    //Tail
    const uint8_t * tail = (const uint8_t*)(data + nblocks*4);

    uint32_t k1 = 0;
    
    switch(len & 3){
        case 3: k1 ^= tail[2] << 16;
        case 2: k1 ^= tail[1] << 8;
        case 1: k1 ^= tail[0];
                k1 *= c1; k1 = rotl(k1,r1); k1 *= c2; h ^= k1;
    };


    scramble(h);
    h ^= len;
    h ^= h >> 16;
    h *= 0x85ebca6b;
	h ^= h >> 13;
	h *= 0xc2b2ae35;
	h ^= h >> 16;

    return h;
}