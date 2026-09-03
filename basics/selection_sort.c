#include <stdio.h>

#define MAX_SIZE 20

void selection_sort(int, int[]);

int main(void)
{
    int nums[MAX_SIZE], count = 0;

    printf("Enter numbers to sort(0 to stop, max 20): ");
    for (int i = 0; i < MAX_SIZE; i++)
    {
        scanf("%d", &nums[i]);

        if (nums[i] != 0)
            printf("Enter number %d: ", i + 2);
        else
            break;

        count++;
    }

    selection_sort(count, nums);

    printf("Selection sort output:");
    for (int i = 0; i < count; i++)
        printf(" %d", nums[i]);

    return 0;
}

void selection_sort(int n, int nums[])
{
    if (n == 0)
        return;

    int index = 0;
    for (int i = 0; i < n; i++)
        if (nums[i] > nums[index])
            index = i;

    if (index != n - 1)
    {
        int temp = nums[n - 1];
        nums[n - 1] = nums[index];
        nums[index] = temp;
    }

    selection_sort(n - 1, nums);
}