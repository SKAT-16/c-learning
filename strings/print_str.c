#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[] = "my name.";
    char *b = "nati";

    strcpy(a, b);
    printf("%s", a);

    return 0;
}
