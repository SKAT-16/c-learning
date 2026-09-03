#include <stdio.h>
#include <stdarg.h>
#include "read_line.h"

#define MAX_PARTS 100
#define NAME_LEN 25

struct part
{
    int number, quantity;
    char name[NAME_LEN + 1];
} inventory[MAX_PARTS] = {{1, 100, "This is the name"}};

int num_parts = 1;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void delete(void);
void print(void);

void print_error(const char *err, ...);

int main(void)
{
    char code;

    for (;;)
    {
        printf("Enter operation code: ");
        scanf(" %c", &code);

        while (getchar() != '\n')
            ;

        switch (code)
        {
        case 'i':
            insert();
            break;
        case 's':
            search();
            break;
        case 'u':
            update();
            break;
        case 'd':
            delete();
            break;
        case 'p':
            print();
            break;
        case 'q':
            return 0;
            break;
        default:
            break;
        }

        printf("\n");
    }

    return 0;
}

int find_part(int number)
{
    for (int i = 0; i < num_parts; i++)
        if (inventory[i].number == number)
            return i;
    return -1;
}

void insert(void)
{
    struct part p;

    if (num_parts == MAX_PARTS)
    {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &p.number);

    if (find_part(p.number) != -1)
    {
        print_error("Part number %d already taken", p.number);
        return;
    }
    else if (p.number < 1)
    {
        print_error("Invalid part number value: %d", p.number);
        return;
    }
    while (getchar() != '\n')
        ;

    printf("Enter part name: ");
    read_line(p.name, NAME_LEN + 1);

    printf("Enter quantity on hand: ");
    scanf("%d", &p.quantity);

    if (p.quantity < 0)
    {
        print_error("Invalid part quantity value: %d", p.quantity);
        return;
    }

    inventory[num_parts++] = p;
}

void search(void)
{
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);

    i = find_part(number);
    if (i >= 0)
    {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].quantity);
    }
    else
        printf("Part not found.\n");
}

void update(void)
{
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);

    i = find_part(number);
    if (i >= 0)
    {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        if (inventory[i].quantity + change < 0)
        {
            print_error("Quantity cannot be less than 0");
            return;
        }
        inventory[i].quantity += change;
    }
    else
        printf("Part not found.\n");
}

void delete(void)
{
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);

    i = find_part(number);
    if (i != -1)
    {
        char c;
        printf("Confirm to delete part %d (y or n): ", i);
        scanf(" %c", &c);

        while (getchar() != '\n')
            ;

        if (c == 'y')
        {
            for (int j = i; j < num_parts - 1; j++)
                inventory[j] = inventory[j + 1];
            num_parts--;
        }
    }
    else
        printf("Part not found.\n");
}

void print(void)
{
    if (num_parts == 0)
    {
        printf("There are no parts in the database\n");
        return;
    }
    int i;

    printf("Part Number\tPart Name\tQuantity on Hand\n");
    for (i = 0; i < num_parts; i++)
        printf("%7d\t%s%11d\n", inventory[i].number, inventory[i].name, inventory[i].quantity);
}

void print_error(const char *err, ...)
{
    va_list args;
    va_start(args, err);

    vprintf(err, args);

    va_end(args);
    printf("\n");
}