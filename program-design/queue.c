#include "queue.h"

struct queue {
    void *item;
    ItemType type;
    struct queue *next;
};

Queue *create(void) { return NULL; }

void push(Queue **q, ItemType type, void *item) {
    if (is_empty(*q)) {
        if ((*q = malloc(sizeof(Queue))) == NULL)
            return;

        (*q)->type = type;
        (*q)->item = item;
        (*q)->next = NULL;
        return;
    }

    Queue *q_ptr = *q;
    while (q_ptr->next != NULL)
        q_ptr = q_ptr->next;

    Queue *p;
    if ((p = malloc(sizeof(Queue))) == NULL)
        return;

    p->item = item;
    p->type = type;
    p->next = NULL;
    q_ptr->next = p;
}

QueueResult pop(Queue **q) {
    QueueResult result;
    if (is_empty(*q)) {
        result.item = NULL;
        result.type = NONE;
        return result;
    }

    Queue *p = *q;
    result.type = p->type;
    result.item = p->item;

    *q = (*q)->next;
    free(p);

    return result;
}

const Queue *peek_first(const Queue *q) { return q; }
const Queue *peek_last(const Queue *q) {
    if (is_empty(q))
        return NULL;

    while (q->next != NULL)
        q = q->next;

    return q;
}

void clear(Queue **q) {
    if (is_empty(*q))
        return;

    Queue *temp;
    while (*q != NULL) {
        temp = (*q)->next;

        if ((*q)->item != NULL)
            free((*q)->item);

        free(*q);
        *q = temp;
    }
}

bool is_empty(const Queue *q) { return q == NULL; }

size_t size(const Queue *q) {
    if (is_empty(q))
        return 0;

    size_t count = 0;
    while (q != NULL) {
        count++;
        q = q->next;
    }

    return count;
}
