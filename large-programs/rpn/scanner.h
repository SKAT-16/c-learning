#include "stack.h"
#include "token.h"

typedef struct {
    Stack *tokens;
    int current;
    const char *source;
} Scanner;

Scanner *scan_tokens(char *str);