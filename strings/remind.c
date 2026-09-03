#include <stdio.h>
#include <string.h>

#define MAX 100

void selection_sort(int, int[], char[][MAX]);

int main(void)
{
    int month[MAX] = {0}, count = 0;
    char reminders[MAX][MAX];

    do
    {
        printf("Enter day and reminder(0 to stop): ");

        scanf("%2d", &month[count]);
        getchar();
        if (month[count] == 0)
            break;

        fgets(reminders[count], sizeof(reminders[count]), stdin);
        count++;
    } while (count < MAX);

    if (count == 0)
    {
        printf("No reminders set");
        return 0;
    }

    selection_sort(count, month, reminders);

    printf("Daily Reminders:\n");
    for (int i = 0; i < count; i++)
    {
        printf("%2d : %s", month[i], reminders[i]);
    }

    return 0;
}

void selection_sort(int n, int nums[], char reminders[][MAX])
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

        char temp_c[MAX] = {0};
        strcpy(temp_c, reminders[n - 1]);
        strcpy(reminders[n - 1], reminders[index]);
        strcpy(reminders[index], temp_c);
    }

    selection_sort(n - 1, nums, reminders);
}