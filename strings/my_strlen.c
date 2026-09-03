#include <stdio.h>
#include <time.h>

// We define how many times to run the loop to get a measurable time
#define ITERATIONS 100000000

size_t my_strlen_1(const char *);
size_t my_strlen_2(const char *);
void start_timer(clock_t *);
double end_timer(clock_t *);

int main(void)
{
    clock_t timer;
    double time_1, time_2;
    const char *test_str = "123abc_this_is_a_longer_test_string_to_make_the_cpu_work";
    volatile size_t dummy = 0; // 'volatile' stops the compiler from deleting our loop during optimization

    // --- TEST FUNCTION 1 (Counter Method) ---
    start_timer(&timer);
    for (long long i = 0; i < ITERATIONS; i++)
    {
        dummy = my_strlen_1(test_str);
    }
    time_1 = end_timer(&timer);
    printf("Function 1 (Counter) Length: %zu | Time: %.4f seconds\n", dummy, time_1);

    // --- TEST FUNCTION 2 (Pointer Subtraction Method) ---
    start_timer(&timer);
    for (long long i = 0; i < ITERATIONS; i++)
    {
        dummy = my_strlen_2(test_str);
    }
    time_2 = end_timer(&timer);
    printf("Function 2 (Pointer) Length: %zu | Time: %.4f seconds\n", dummy, time_2);

    printf("Time difference is: %.4f", (time_1 - time_2));

    return 0;
}

size_t my_strlen_1(const char *s)
{
    size_t count = 0;
    while (*s++)
        count++;
    return count;
}

size_t my_strlen_2(const char *s)
{
    const char *p = s;
    while (*s)
        s++;
    return s - p;
}

void start_timer(clock_t *start)
{
    *start = clock();
}

double end_timer(clock_t *start)
{
    clock_t end = clock();
    return ((double)(end - *start)) / CLOCKS_PER_SEC;
}
