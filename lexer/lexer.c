#include "lexer.h"

int isKeyword(const char *str, int len, const char *kw)
{
    return (strlen(kw) == (size_t)len) && (strncmp(str, kw, len) == 0);
}

Token tokenizeNum(const char *p)
{

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
    Token tokenizeOperators(const char *p)
    {
        if (*p == '=' && *(p + 1) == '=')
            return makeToken(TK_EQUALS, p, 2, 0);
        if (*p == '<' && *(p + 1) == '=')
            return makeToken(TK_LEQ, p, 2, 0);
        if (*p == '>' && *(p + 1) == '=')
            return makeToken(TK_GEQ, p, 2, 0);
        if (*p == '!' && *(p + 1) == '=')
            return makeToken(TK_NEQ, p, 2, 0);

        for (size_t i = 0; i < sizeof(SingleCharOperators) / sizeof(SingleCharOperators[0]); i++)
        {
            if (*p == SingleCharOperators[i].op)
                return makeToken(SingleCharOperators[i].type, p, 1, 0);
        }

        return makeToken(TK_UNKNOWN, p, 1, 0);
    }
}

Token tokenizeKeywords(const char *p, int *advance)
{
    const char *idStart = p;
    while (isalnum(*p) || *p == '_')
    {
        p++;
    }
    int len = p - idStart;
    *advance = len;

    switch (*idStart)
    {
    case 'p':
        if (isKeyword(idStart, len, "print"))
            return makeToken(TK_KEYWORD_PRINT, idStart, len, 0);
        break;

    case 'w':
        if (isKeyword(idStart, len, "while"))
            return makeToken(TK_KEYWORD_WHILE, idStart, len, 0);
        break;

    case 'i':
        if (isKeyword(idStart, len, "if"))
            return makeToken(TK_KEYWORD_IF, idStart, len, 0);
        break;

    case 'e':
        if (isKeyword(idStart, len, "else"))
            return makeToken(TK_KEYWORD_ELSE, idStart, len, 0);
        break;
    }
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
            p += currToken.length;
        }
        else if (isalpha(*p) || *p == '_')
        {
            int advance;
            currToken = tokenizeKeywords(p, &advance);
            p += advance;
        }
        else
        {
            currToken = tokenizeOperators(p);
            p++;
        }
        pushToken(currToken, &tokens);
    }
    pushToken(makeToken(TK_EOF, p, 0, 0), &tokens);
    return tokens;
}