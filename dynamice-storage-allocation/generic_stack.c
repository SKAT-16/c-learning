#include "generic_stack.h"

int main(void) {
    char *str = "some text";
    int a = 12, b = 13;
    float c[] = {1.1f, 2.2f};

    Stack *s = NULL;
    push(&s, &a);
    push(&s, &b);
    push(&s, c);
    push(&s, str);

    printf("Size is %zu\n", size(s));
    clear(&s);
    printf("Size is %zu\n", size(s));
    printf("S is null: %d", s == NULL);

    return 0;
}

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

void *peek(const Stack *first) {
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
        // free((*first)->item); -> this should be uncommented for mem-allocated
        // values
        free((*first));
        *first = temp;
    }
}