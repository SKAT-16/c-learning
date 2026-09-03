#include <stdio.h>

int main(void) {
    // rename("file.txt", "modified.txt");
    // rename("file.txt", "modified.txt");

    FILE *file;

    if ((file = fopen("modified.txt", "r")) == NULL) {
        printf("Can't open file.txt");
        return 1;
    }

    fclose(file);

    printf("Temp is: %u", TMP_MAX);

    return 0;
}