#include "tokens.h"

static const struct
{
    char op;
    TokenType type;
} SingleCharOperators[] = {
    {'+', TK_ADD},
    {'-', TK_SUBTRACT},
    {'/', TK_DIVIDE},
    {'*', TK_MULTIPLY},
    {'%', TK_MODULO},
    {'(', TK_LPAREN},
    {')', TK_RPAREN},
    {'{', TK_LBRACE},
    {'}', TK_RBRACE},
    {';', TK_SEMICOLON},
};

Token makeToken(TokenType type, const char *start, int length, int value);
TokenArray tokenize(const char *source);