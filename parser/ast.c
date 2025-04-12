#include "ast.h"

ASTNode *newASTNode(ASTNodeType type)
{
    ASTNode *node = malloc(sizeof(ASTNode));
    if (!node)
    {
        fprintf(stderr, "Out of memory (AST Node)!\n");
        exit(EXIT_FAILURE);
    }
    node->type = type;
    return node;
}