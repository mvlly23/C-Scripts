#include <unistd.h>
#include <string.h>
#include <pthread.h>
/* Only for the debug printf */
#include <stdio.h>
#include "memory.h"

header_t *head, *tail;
pthread_mutex_t global_malloc_lock;

void *malloc(size_t size){
    size_t totalSize;
    void *block;
    header_t *header;
    if(!size)
        return NULL;
    
    pthread_mutex_lock(&global_malloc_lock);
    header = get_free_block(size);
    if(header){
        header -> s.is_free = 0;
        pthread_mutex_unlock(&global_malloc_lock);
        return (void*)(header + 1);
    }
    totalSize = sizeof(header_t) + size;
    block = sbrk(totalSize);
    if(block == (void*) -1)
        return NULL;
    header = block;
    header -> s.size = size;
    header -> s.is_free = 0;
    header -> s.next = NULL;
    if(!head)
        head = header;
    if(tail)
        tail -> s.next = header;
    tail = header;
    pthread_mutex_unlock(&global_malloc_lock);
    return (void*)(header + 1);
}

header_t *get_free_block(size_t size){
    header_t *curr = head;
    while(curr){
        if(curr -> s.size >= size && curr -> s.is_free)
            return curr;
        curr = curr -> s.next;
    }
    return NULL;
}

void free(void* block){
    header_t *header, *tmp;
    void *programBreak;

    if(!block)
        return;
    pthread_mutex_lock(&global_malloc_lock);
    header = (header_t*)block - 1;

    programBreak = sbrk(0);
    if((char*)block + header -> s.size == programBreak){
        if (head == tail)
            head = tail = NULL;
        else {
            tmp = head;
            while(tmp){
                if(tmp -> s.next == tail){
                    tmp -> s.next = NULL;
                    tail = tmp;
                }
                tmp = tmp -> s.next;
            }
        }
        sbrk(0 - sizeof(header_t) - header -> s.size);
        pthread_mutex_unlock(&global_malloc_lock);
        return;
    }
    header -> s.is_free = 1;
    pthread_mutex_unlock(&global_malloc_lock);
}

void *calloc(size_t num, size_t nsize){
	size_t size;
	void *block;
	if (!num || !nsize)
		return NULL;
	size = num * nsize;
	/* check mul overflow */
	if (nsize != size / num)
		return NULL;
	block = malloc(size);
	if (!block)
		return NULL;
	memset(block, 0, size);
	return block;
}

void *realloc(void *block, size_t size){
	header_t *header;
	void *ret;
	if (!block || !size)
		return malloc(size);
	header = (header_t*)block - 1;
	if (header->s.size >= size)
		return block;
	ret = malloc(size);
	if (ret) {
		
		memcpy(ret, block, header->s.size);
		free(block);
	}
	return ret;
}