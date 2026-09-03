#include <stdio.h>
#include <stdbool.h>

#define N 10

int sum_array(const int *, int);

bool search(const int a[], int n, int key);

double inner_product(const double *a, const double *b, int n);

int main(void)
{
    int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = &a[0], *q = &a[N - 1], temp;
    while (p < q)
    {
        temp = *p;
        *p++ = *q;
        *q-- = temp;
    }

    printf("Array is: ");
    for (int i = 0; i < N; i++)
        printf(" %d", a[i]);

    printf("\nSum is: %d", sum_array(a, N));

    int key = 4;
    printf("\nCheck for %d is %s", key, search(a, N, key) ? "True" : "False");

    double b[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("\nInner Product is %.2f", inner_product(b, b, N));

    return 0;
}

int sum_array(const int *p, int n)
{
    int sum = 0;
    for (const int *q = p; q < p + n; q++)
        sum += *q;

    return sum;
}

bool search(const int a[], int n, int key)
{
    for (const int *p = a; p < a + n; p++)
        if (*p == key)
            return true;

    return false;
}

double inner_product(const double *a, const double *b, int n)
{
    if (n <= 0)
        return 0.0;

    return (a[n - 1] * b[n - 1]) + inner_product(a, b, n - 1);
}