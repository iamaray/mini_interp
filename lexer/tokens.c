#include "tokens.h"

void initTokenArray(TokenArray *arr)
{
    arr->capacity = 64;
    arr->count = 0;
    arr->data = malloc(sizeof(Token) * arr->capacity);
    if (!arr->data)
    {
        fprintf(stderr, "Out of memory (token array)!\n");
        exit(EXIT_FAILURE);
    }
}

void pushToken(Token token, TokenArray *arr)
{
    if (arr->count >= arr->capacity)
    {
        arr->capacity *= 2;
        arr->data = realloc(arr->data, sizeof(Token) * arr->capacity);
        if (!arr->data)
        {
            fprintf(stderr, "Out of memory (token array realloc)!\n");
            exit(EXIT_FAILURE);
        }
    }
    arr->data[arr->count++] = token;
}

Token makeToken(TokenType type, const char *start, int length, int value)
{
    Token t;

    t.type = type;
    t.start = start;
    t.length = length;
    t.value = value;

    return t;
}