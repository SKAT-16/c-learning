#include <stdio.h>

int read_line(char *str, int n) {
    int i = 0, ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (i < n)
            str[i++] = ch;
    }

    str[i] = '\0';
    return i;
}