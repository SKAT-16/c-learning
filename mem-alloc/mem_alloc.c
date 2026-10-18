#include "mem_alloc.h"
#include <string.h>
#include <unistd.h>

static header_t *head, *tail;
static pthread_mutex_t global_malloc_lock = PTHREAD_MUTEX_INITIALIZER;

static header_t *get_free_block(size_t size) {
    header_t *curr = head;
    while (curr) {
        if (curr->s.is_free && curr->s.size >= size)
            return curr;
        curr = curr->s.next;
    }

    return NULL;
}

void *malloc_ma(size_t size) {
    size_t total_size;
    void *block;
    header_t *header;

    if (!size)
        return NULL;

    pthread_mutex_lock(&global_malloc_lock);

    header = get_free_block(size);
    if (header) {
        header->s.is_free = 0;
        pthread_mutex_unlock(&global_malloc_lock);

        return (void *)(header + 1);
    }

    total_size = sizeof(header_t) + size;
    block = sbrk(total_size);
    if (block == (void *)-1) {
        pthread_mutex_unlock(&global_malloc_lock);
        return NULL;
    }

    // In C, there is no need to cast a void* to any other pointer type, it is
    // always safely promoted.
    header = block;
    header->s.size = size;
    header->s.is_free = 0;
    header->s.next = NULL;

    if (!head)
        head = header;
    if (tail)
        tail->s.next = header;
    tail = header;

    pthread_mutex_unlock(&global_malloc_lock);
    return (void *)(header + 1);
}

void *calloc_ma(size_t num, size_t nsize) {
    size_t size;
    void *block;

    if (!num || !nsize)
        return NULL;

    size = num * nsize;

    /* check mul overflow */
    if (nsize != size / num)
        return NULL;

    block = malloc_ma(size);
    if (!block)
        return NULL;

    memset(block, 0, size);
    return block;
}

void *realloc_ma(void *block, size_t size) {
    header_t *header;
    void *ret;

    if (!block || !size)
        return malloc_ma(size);

    header = (header_t *)block - 1;
    if (header->s.size >= size)
        return block;

    ret = malloc_ma(size);
    if (ret) {
        memcpy(ret, block, size);
        free_ma(block);
    }

    return ret;
}

void free_ma(void *block) {
    header_t *header, *tmp;
    void *program_break;

    if (!block)
        return;

    pthread_mutex_lock(&global_malloc_lock);
    header = (header_t *)block - 1;

    program_break = sbrk(0);
    if ((char *)block + header->s.size == program_break) {
        if (head == tail) {
            head = tail = NULL;
        } else {
            tmp = head;
            while (tmp) {
                if (tmp->s.next == tail) {
                    tmp->s.next = NULL;
                    tail = tmp;
                }
                tmp = tmp->s.next;
            }
        }

        sbrk(0 - sizeof(header) - header->s.size);
        pthread_mutex_unlock(&global_malloc_lock);
        return;
    }

    header->s.is_free = 1;
    pthread_mutex_unlock(&global_malloc_lock);
}