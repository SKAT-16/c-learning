#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void push(Stack **first, void *item) {
    Stack *temp;
    if ((temp = malloc(sizeof(Stack))) == NULL) {
        fprintf(stderr, "Out of memory during stack push operation");
        exit(EXIT_FAILURE);
    }

    temp->item = item;
    temp->next = *first;
    *first = temp;
}

void *pop(Stack **first) {
    if (*first == NULL)
        return NULL;

    Stack *temp = *first;
    void *p = temp->item;
    *first = temp->next;

    free(temp);
    return p;
}

void *peek_top(const Stack *first) {
    if (first == NULL)
        return NULL;
    return first->item;
}

bool is_empty(const Stack *first) { return first == NULL; }

size_t size(Stack *first) {
    if (first == NULL)
        return 0;

    size_t s = 0;
    while (first != NULL) {
        s++;
        first = first->next;
    }

    return s;
}

void clear(Stack **first) {
    if (first == NULL || *first == NULL)
        return;

    Stack *temp;
    while (*first != NULL) {
        temp = (*first)->next;
        free((*first)->item);
        free((*first));
        *first = temp;
    }
}