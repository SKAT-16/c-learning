#include "mem_alloc.h"
#include <stdio.h>

int main() {
    int *b = malloc_ma(sizeof(int));
    *b = 4;

    printf("%d\n", *b);

    free_ma(b);
    return 0;
}