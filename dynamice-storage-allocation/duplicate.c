#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *duplicate(char *str) {
    if (str == NULL)
        return NULL;

    char *p = str;
    while (*p != '\0')
        p++;

    size_t bytes = (p - str) + 1;

    char *dup;
    if ((dup = (char *)malloc(bytes)) == NULL)
        return NULL;

    strcpy(dup, str);
    return dup;
}

int *initialize(int n, int initial_value) {
    if (n == 0)
        return NULL;

    int *p;
    if ((p = malloc(n * sizeof(int))) == NULL)
        return NULL;

    for (int *q = p; q < p + n; q++)
        *q = initial_value;

    return p;
}

int main(void) {
    char *str = "123", *str_dup;
    int *i;
    str_dup = duplicate(str);
    i = initialize(3, 5);

    printf("duplicate is: %s", str_dup);
    printf("\nArray initialize as: %d", *i);

    free(str_dup);
    free(i);
    return 0;
}