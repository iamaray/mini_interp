#ifndef PARSER_H
#define PARSER_H

#include "ast.h"

/* Global variables */
extern Token *g_tokens;
extern int g_tokens;
extern int g_tokenCount;

ASTNode *parseProgram();

#endif