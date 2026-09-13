#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// #define NDEBUG

int main(void) {
    int i = -1;
    int a[] = {1, 2, 3, 4};

#ifdef NDEBUG
    assert(i >= 0);
#endif
    printf("a[i] is %d\n", a[i]);

    errno = 0;

    double x = -1, y = sqrt(x);
    if (errno != 0) {
        perror("sqrt error");
        exit(EXIT_FAILURE);
    }

    printf("Y is %.2f", y);

    return 0;
}