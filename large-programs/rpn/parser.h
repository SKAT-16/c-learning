#include "stack.h"
#include "token.h"

typedef enum {
    EXPR_BINARY,
} ExprType;

typedef struct Expr Expr;

typedef struct {
    Expr *left;
    Token oper;
    Expr *right;
} BinaryExpr;

struct Expr {
    ExprType type;
    union {
        BinaryExpr binary;
    };
};

Expr *parse_tokens(Stack *first);