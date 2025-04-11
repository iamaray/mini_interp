#include "tokens.h"

Token makeToken(TokenType type, const char *start, int length, int value);
TokenArray tokenize(const char *source);