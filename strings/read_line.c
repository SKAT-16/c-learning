#include <stdio.h>

#define N 20

int read_line(char[], int);
int read_line_ai_suggestions(char[], int);

int main(void)
{
    char sentence[N];

    printf("Enter a sentence: ");
    read_line(sentence, N);

    printf("You said: \"%s\"", sentence);
    return 0;
}

int read_line(char str[], int n)
{
    int i = 0, ch;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;

    str[i] = '\0';

    return i;
}

int read_line_ai_suggestions(char str[], int n)
{
    int ch, i = 0;

    // Stop if we hit EOF, a newline, OR if we reach n - 1 (saving 1 slot for '\0')
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (i < n - 1)
        {
            str[i++] = ch;
        }
    }

    str[i] = '\0'; /* Safely terminates within bounds (at most index n-1) */
    return i;      /* Returns the exact number of characters stored */
}
