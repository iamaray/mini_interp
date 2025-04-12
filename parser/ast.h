#ifndef AST_H
#define AST_H

#include "tokens.h"

typedef enum
{
    AST_ASSIGNMENT,
    AST_PRINT,
    AST_WHILE,
    AST_BLOCK,
    AST_BINARY,
    AST_INT_LITERAL,
    AST_VARIABLE
} ASTNodeType;

typedef struct ASTNode
{
    ASTNodeType type;
    union
    {
        struct
        {
            char *var;
            struct ASTNode *expr;
        } assignment;

        struct
        {
            struct ASTNode *expr;
        } print_stmt;
        struct
        {
            struct ASTNode *cond;
            struct ASTNode *body;
        } while_stmt;
        struct
        {
            struct ASTNode **statements;
            int count;
        } block;
        struct
        {
            struct ASTNode *left;
            TokenType op;
            struct ASTNode *right;
        } binary;

        int int_val; // numerical variable
        char *var;   // variable identification
    };
} ASTNode;

ASTNode *newASTNode(ASTNodeType type);

#endif