#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX_WORD_SIZE 20
#define VAL_1 "AEILNORSTU"
#define VAL_2 "DG"
#define VAL_3 "BCMP"
#define VAL_4 "FHVWY"
#define VAL_5 "K"
#define VAL_8 "JX"
#define VAL_10 "QZ"

bool includes(int n, char str[], char c)
{
    for (int i = 0; i < n; i++)
        if (str[i] == c)
            return true;

    return false;
}

int main(void)
{
    char word[MAX_WORD_SIZE];
    int totalFaceValue = 0;

    printf("Enter a word: ");
    scanf("%19s", word);

    for (int i = 0; i < (int)(sizeof(word) / sizeof(char)); i++)
    {
        char c = toupper(word[i]);

        if (includes(10, VAL_1, c))
            totalFaceValue++;
        else if (includes(2, VAL_2, c))
            totalFaceValue += 2;
        else if (includes(4, VAL_3, c))
            totalFaceValue += 3;
        else if (includes(5, VAL_4, c))
            totalFaceValue += 4;
        else if (includes(1, VAL_5, c))
            totalFaceValue += 6;
        else if (includes(2, VAL_8, c))
            totalFaceValue += 8;
        else if (includes(2, VAL_10, c))
            totalFaceValue += 10;
    }

    printf("Total Face Value is: %d", totalFaceValue);
    return 0;
}