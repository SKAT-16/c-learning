#include "scanner.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static Scanner scanner;

void operator(TokenType type);
void number();

void add_token(TokenType type, double value);

char advance();
bool match(char c);
char peek();
char peek_next();

bool is_digit(char c);
bool is_at_end();

Scanner *scan_tokens(char *src) {
    scanner.source = src;
    scanner.current = 0;
    clear(&scanner.tokens);

    while (!is_at_end()) {
        char c = advance();
        switch (c) {
            case '+':
                operator(PLUS);
                break;
            case '-':
                operator(MINUS);
                break;
            case '*':
                operator(STAR);
                break;
            case '/':
                operator(SLASH);
                break;
            case '%':
                operator(PERCENT);
                break;
            case ',':
                operator(COMMA);
                break;
            case ' ':
            case '\r':
            case '\t':
            case '\n':
                break;
            default: {
                if (is_digit(c))
                    number();
            }
        }
    }

    return &scanner;
}

void operator(TokenType type) { add_token(type, type); }

void number() {
    int start = scanner.current - 1;

    while (is_digit(peek()))
        advance();
    if (peek() == '.' && is_digit(peek_next())) {
        advance();
        while (is_digit(peek()))
            advance();
    }

    int length = scanner.current - start;
    char num[length + 1];

    strncpy(num, scanner.source + start, length);
    num[length] = '\0';

    add_token(NUMBER, atof(num));
}

void add_token(TokenType type, double value) {
    Token *new_token;
    if ((new_token = malloc(sizeof(Token))) == NULL) {
        fprintf(stderr, "Out of memory during new creation operation.");
        exit(EXIT_FAILURE);
    }

    *new_token = (Token){.type = type, .value = value};
    push(&scanner.tokens, new_token);
}

bool is_digit(char c) {
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

char advance() { return scanner.source[scanner.current++]; }

char peek() { return scanner.source[scanner.current]; }

char peek_next() { return scanner.source[scanner.current + 1]; }

bool match(char c) {
    if (is_at_end() || peek() != c)
        return false;

    scanner.current++;
    return true;
}

bool is_at_end() { return scanner.current >= (int)strlen(scanner.source); }