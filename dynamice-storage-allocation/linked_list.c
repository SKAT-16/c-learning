#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

void add_to_list(struct node *, int);
void print_list(struct node *);
struct node *search_list(struct node *, int);

int main(void) {
    struct node list = {.value = 10};

    add_to_list(&list, 20);
    add_to_list(&list, 30);
    add_to_list(&list, 40);
    add_to_list(&list, 50);
    add_to_list(&list, 60);
    print_list(&list);

    return 0;
}

void add_to_list(struct node *list, int value) {
    while (list->next != NULL)
        list = list->next;

    if ((list->next = malloc(sizeof(struct node))) != NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    } else
        list->next->value = value;
}

struct node *search_list(struct node *list, int n) {
    for (struct node *p = list; p != NULL; p = p->next)
        if (p->value == n)
            return p;
    return NULL;
}

void print_list(struct node *list) {
    printf("Values are:\n");
    for (struct node *p = list; p != NULL; p = p->next)
        printf("%d\n", p->value);
}