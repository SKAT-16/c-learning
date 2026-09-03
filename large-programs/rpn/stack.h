#include <stdbool.h>

typedef struct stack {
    void *item;
    struct stack *next;
} Stack;

void push(Stack **, void *);

void *pop(Stack **);

void *peek_top(const Stack *);

bool is_empty(const Stack *);

size_t size(Stack *);

void clear(Stack **);
