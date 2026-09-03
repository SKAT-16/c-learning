typedef enum {
    PLUS = '+',
    MINUS = '-',
    STAR = '*',
    SLASH = '/',

    PERCENT = '%',
    COMMA = ',',

    NUMBER = 'N',
    EOL = '\0',
} TokenType;

typedef struct {
    double value;
    TokenType type;
} Token;
