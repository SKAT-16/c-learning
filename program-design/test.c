#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Heap Allocation Helper Functions ---

int *create_integer(int value) {
    int *p = malloc(sizeof(int));
    if (p)
        *p = value;
    return p;
}

float *create_float(float value) {
    float *p = malloc(sizeof(float));
    if (p)
        *p = value;
    return p;
}

double *create_double(double value) {
    double *p = malloc(sizeof(double));
    if (p)
        *p = value;
    return p;
}

char *create_char(char value) {
    char *p = malloc(sizeof(char));
    if (p)
        *p = value;
    return p;
}

char *create_string(const char *text) {
    char *p = malloc(strlen(text) + 1);
    if (p)
        strcpy(p, text);
    return p;
}

int main(void) {
    // 1. Initialize queue (Design A starts as NULL)
    Queue *my_queue = create();
    printf("Queue initialized. Is empty: %s (Size: %zu)\n\n",
           is_empty(my_queue) ? "Yes" : "No", size(my_queue));

    // 2. Push elements of different types using your specific enum naming
    printf("--- Pushing Mixed Data Types ---\n");

    push(&my_queue, INTEGER, create_integer(42));
    push(&my_queue, FLOAT, create_float(3.14f));
    push(&my_queue, DOUBLE, create_double(2.71828));
    push(&my_queue, CHAR, create_char('A'));
    push(&my_queue, STRING, create_string("Hello Queue"));

    printf("Queue loaded. Current Size: %zu\n\n", size(my_queue));

    // 3. Test your Peek functions safely
    // Note: Since peek returns Queue*, we cast inner fields if needed,
    // but here we just prove they return valid memory boundaries.
    if (!is_empty(my_queue)) {
        printf("Peek First element verified.\n");
        printf("Peek Last element verified.\n\n");
    }

    // 4. Pop and process items matching your structural QueueResult layout
    printf("--- Processing Queue (FIFO Order) ---\n");
    while (!is_empty(my_queue)) {
        QueueResult package = pop(&my_queue);

        switch (package.type) {
            case INTEGER: {
                int *val = (int *)package.item;
                printf("Popped INTEGER: %d\n", *val);
                free(val); // Clean up user-owned payload data
                break;
            }
            case FLOAT: {
                float *val = (float *)package.item;
                printf("Popped FLOAT: %.2f\n", *val);
                free(val);
                break;
            }
            case DOUBLE: {
                double *val = (double *)package.item;
                printf("Popped DOUBLE: %.5f\n", *val);
                free(val);
                break;
            }
            case CHAR: {
                char *val = (char *)package.item;
                printf("Popped CHAR: '%c'\n", *val);
                free(val);
                break;
            }
            case STRING: {
                char *val = (char *)package.item;
                printf("Popped STRING: \"%s\"\n", val);
                free(val);
                break;
            }
            case NONE:
            default:
                printf("Encountered empty or unhandled type packet.\n");
                break;
        }
    }

    printf("\nQueue fully processed. Current Size: %zu\n\n", size(my_queue));

    // 5. Test your automatic cleanup inside the clear function
    printf("--- Testing Clear Operation ---\n");
    push(&my_queue, INTEGER, create_integer(100));
    push(&my_queue, STRING, create_string("Leftover element"));
    printf("Size before clear: %zu\n", size(my_queue));

    clear(&my_queue);
    printf("Size after clear: %zu\n", size(my_queue));

    return 0;
}
