#include "murmur3.h"
#include "murmur_test.h"

int main(){
    char test[] = "this is a test string";
    uint8_t num;
    memcpy(&num, test, 1);
    uint32_t hash = murmur3(&num, sizeof(num), 2323);
    uint32_t hash_test = murmur3_32(&num, sizeof(num), 2323);
    printf("%d\n%d\n\n", hash, hash_test);
    printf("Are they equal?: %d\n", hash_test == hash);
    return 0;
}