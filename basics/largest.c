#include <stdio.h>

int main(void)
{
    int num, largest = 0;
    do
    {
        printf("Enter a number: ");
        scanf("%d", &num);

        if (num > largest)
            largest = num;
    } while (num > 0);

    printf("Largest number is %d", largest);
}