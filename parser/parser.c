#include "parser.h"
#include "globals.h"

int g_current = 0;
Token currentToken()
{
    return g_tokens[g_current];
}

Token peekToken(int offset)
{
    int pos = g_current + offset;
    if (pos < g_tokenCount)
        return g_tokens[pos];
    return g_tokens[g_tokenCount - 1];
}

void advance()
{
    if (g_current < g_tokenCount)
        g_current++;
}

void expect(TokenType type)
{
    if (currentToken().type != type)
    {
        fprintf(stderr, "Unexpected token at position %ld. Expected token type %d but got %d.\n",
                currentToken().start - "", type, currentToken().type);
        exit(EXIT_FAILURE);
    }
    advance();
}

ASTNode *parseStatement();
ASTNode *parseExpr();
ASTNode *parseEquality();
ASTNode *parseRelational();
ASTNode *parseAdd();
ASTNode *parseMul();
ASTNode *parsePrimary();

ASTNode *parserProgram()
{
    ASTNode *node = newASTNode(AST_BLOCK);
    node->block.count = 0;
    node->block.statements = NULL;

    while (currentToken().type != TK_EOF)
    {
        node->block.statements = realloc(
            node->block.statements,
            sizeof(ASTNode *) * (node->block.count + 1));

        node->block.statements[node->block.count++] = parseStatement();
    }
    return node;
}

