#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum
{
    TK_INT,
    TK_IDENTIFIER,
    TK_KEYWORD_IF,
    TK_KEYWORD_ELSE,
    TK_KEYWORD_WHILE,
    TK_ASSIGN,
    TK_SEMICOLON,
    TK_LPAREN,
    TK_RPAREN,
    TK_LBRACE,
    TK_RBRACE,
    TK_ADD,
    TK_SUBTRACT,
    TK_MULTIPLY,
    TK_DIVIDE,
    TK_MODULO,
    TK_LT,
    TK_LEQ,
    TK_GT,
    TK_GEQ,
    TK_EQUALS,
    TK_NEQ,
    TK_EOF,
    TK_UNKNWON
} TokenType;

typedef struct
{
    TokenType type;
    const char *start;
    int length;
    int value;
} Token;

typedef struct
{
    Token *token;
    int capacity;
    int count;
} TokenArray;

void initTokenArray(TokenArray *arr);
void pushToken(Token token, TokenArray *arr);