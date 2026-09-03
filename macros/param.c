#include <stdio.h>
#include <string.h>

#define CUBE(x) ((x) * (x) * (x))
#define REM_4(x) (x) % 4

#define TO_STRING(x) #x
#define STRINGIFY(x) TO_STRING(x)
#define LINE_FILE                                                              \
    "Line " STRINGIFY(__LINE__) " of file " STRINGIFY(__FILE_NAME__)

double test(double a) { return a; }

int main(void) {
    int a = 5;
    double b = 3.5;
    const char *str = LINE_FILE;

    printf("Cube values are %d, %.2f", CUBE(a), CUBE(b));
    printf("\nReminder values are %d, %d", REM_4(a), (int)REM_4(b));
    printf("\nStr is %s", str);

    double (*f)(double) = test;
    printf("\nTest: %f", f(2));

    return 0;
}