#ifndef MEM_ALLOC_H
#define MEM_ALLOC_H

#include <pthread.h>
#include <stddef.h>

typedef char ALIGN[16];

union header {
    struct {
        size_t size;
        unsigned is_free;
        union header *next;
    } s;
    ALIGN stub;
};
typedef union header header_t;

void *malloc_ma(size_t size);
void *calloc_ma(size_t num, size_t nsize);
void *realloc_ma(void *block, size_t size);
void free_ma(void *block);

#endif