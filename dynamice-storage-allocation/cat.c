#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strcat_2(const char *, const char *, char **);

int main(void) {
    char *str1 = "HI Bro", *str2 = "Call Me", *result = NULL;

    strcat_2(str1, str2, &result);

    printf("Concatenated: %s", result);

    return 0;
}

void strcat_2(const char *str1, const char *str2, char **result) {
    if ((*result = malloc(strlen(str1) + strlen(str2) + 1)) == NULL) {
        printf("Error: malloc failed in concat\n");
        exit(EXIT_FAILURE);
    }

    strcpy(*result, str1);
    strcat(*result, str2);
}
