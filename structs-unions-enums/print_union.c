#include <stdio.h>

union
{
    char str[5];
    int i;
} u;

int main(void)
{
    printf("Size of u %llu", sizeof(u));

    return 0;
}