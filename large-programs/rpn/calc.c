#include "read_line.h"
#include "scanner.h"
#include <stdio.h>

#define EXPR_LEN 100

void print_rpn(Stack *);

int main(void) {
    char expr[EXPR_LEN];
    FILE for (;;) {
        printf("Enter an expression to evaluate(q to exit): ");
        read_line(expr, EXPR_LEN + 1);

        if (expr[0] == 'q')
            break;

        Scanner *scan = scan_tokens(expr);
        print_rpn(scan->tokens);
    }

    return 0;
}

// void print_rpn(Stack *first) {
//     if (first == NULL)
//         return;
//     Token left = *(Token *)first->item, operator = *(Token
//     *)first->next->item,
//           right = *(Token *)first->next->next->item;
//     print_rpn(first->next->next->next);

//     printf("%.2f%.2f%c", left.value, right.value, operator.type);
// }