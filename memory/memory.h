#ifndef MEMORY_H_
#define MEMORY_H_

typedef char ALIGN[16];

union header{
    struct header_t {
        size_t size;
        unsigned is_free;
        struct header_t *next;
    } s;
    ALIGN stub;
};
typedef union header header_t;

void *malloc(size_t size);
header_t *get_free_block(size_t size);
void free(void* block);
void *calloc(size_t num, size_t nsize);
void *realloc(void *block, size_t size);

#endif //MEMORY_H_