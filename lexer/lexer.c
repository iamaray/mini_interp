#include "lexer.h"

int isKeyword(const char *str, int len, const char *kw)
{
    return (strlen(kw) == (size_t)len) && (strncmp(str, kw, len) == 0);
}

Token tokenizeNum(const char *p)
{
    // if (isdigit(*p))

    int value = 0;
    const char *numStart = p;

    while (isdigit(*p))
    {
        value = value * 10 + (*p - '0');
        p++;
    }
    return makeToken(TK_INT, p, p - numStart, value);
}

Token tokenizeOperators(const char *p)
{
    switch (*p)
    {
    case '=':
        if (*(p + 1) == '=')
            return makeToken(TK_EQUALS, p, 2, 0);
        return makeToken(TK_ASSIGN, p, 1, 0);
    case '+':
        return makeToken(TK_ADD, p, 1, 0);
    case '-':
        return makeToken(TK_SUBTRACT, p, 1, 0);
    case '/':
        return makeToken(TK_DIVIDE, p, 1, 0);
    case '*':
        return makeToken(TK_MULTIPLY, p, 1, 0);
    case '%':
        return makeToken(TK_MODULO, p, 1, 0);
    case '<':
        if (*(p + 1) == '=')
            return makeToken(TK_LEQ, p, 2, 0);
        return makeToken(TK_LT, p, 1, 0);
    case '>':
        if (*(p + 1) == '=')
            return makeToken(TK_GEQ, p, 2, 0);
        return makeToken(TK_GT, p, 1, 0);
    case '(':
        return makeToken(TK_LPAREN, p, 1, 0);
    case ')':
        return makeToken(TK_RPAREN, p, 1, 0);
    case '{':
        return makeToken(TK_LBRACE, p, 1, 0);
    case '}':
        return makeToken(TK_RBRACE, p, 1, 0);
    case ';':
        return makeToken(TK_SEMICOLON, p, 1, 0);
    case '!':
        if (*(p + 1) == '=')
            return makeToken(TK_NEQ, p, 2, 0);
        break;
    default:
        return makeToken(TK_UNKNOWN, p, 1, 0);
    }
}

// check alphabetical first
void tokenizeKeywords(const char *p)
{
    const char *idStart = p;
    while (isalnum(*p) || *p == '_')
    {
        p++;
    }
    int len = p - idStart;
    if (isKeyword(idStart, len, "print"))
        return makeToken(TK_KEYWORD_PRINT, idStart, len, 0);
    else if (isKeyword(idStart, len, "while"))
        return makeToken(TK_KEYWORD_WHILE, idStart, len, 0);
    else if (isKeyword(idStart, len, "if"))
        return makeToken(TK_KEYWORD_IF, idStart, len, 0);
    else if (isKeyword(idStart, len, "else"))
        return makeToken(TK_KEYWORD_ELSE, idStart, len, 0);
    else
        return makeToken(TK_IDENTIFIER, idStart, len, 0);
}

TokenArray tokenize(const char *source)
{

    TokenArray tokens;
    initTokenArray(&tokens);

    const char *p = source;

    while (*p != '\0')
    {
        if (isspace(*p))
        {
            p++;
            continue;
        }

        if (*p == '/' && *(p + 1) == '/')
        {
            p += 2;
            while (*p && *p != '\n')
                p++;

            continue;
        }

        Token currToken;
        if (isdigit(*p))
        {
            currToken = tokenizeNum(p);
        }
        else if (isalpha(*p) || *p == '_')
        {
            currToken = tokenizeOperators(p);
        }
        else
        {
            currToken = tokenizeOperators(p);
        }
        pushToken(currToken, &tokens);
    }
    pushToken(makeToken(TK_EOF, p, 0, 0), &tokens);
    return tokens;
}
