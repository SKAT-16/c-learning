#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdlib.h>

typedef enum { INTEGER, FLOAT, DOUBLE, CHAR, STRING, NONE } ItemType;

typedef struct queue Queue;

typedef struct {
    void *item;
    ItemType type;
} QueueResult;

Queue *create(void);

void push(Queue **, ItemType, void *);
QueueResult pop(Queue **);
const Queue *peek_first(const Queue *);
const Queue *peek_last(const Queue *);
void clear(Queue **);

bool is_empty(const Queue *);
size_t size(const Queue *);

#endif