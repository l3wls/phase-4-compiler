#include "tree.h"
#include "strtab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
tree *ast = NULL;

/* string values for ast node types, makes tree output more readable */
char *nodeNames[34] = {"program", "declList", "decl", "varDecl", "typeSpecifier",
                       "funDecl", "formalDeclList", "formalDecl", "funBody",
                       "localDeclList", "statementList", "statement", "compoundStmt",
                       "assignStmt", "condStmt", "loopStmt", "returnStmt", "expression",
                       "relop", "addExpr", "addop", "term", "mulop", "factor",
                       "funcCallExpr", "argList", "integer", "identifier", "var",
                       "arrayDecl", "char", "funcTypeName", "string"};

char *typeNames[3] = {"int", "char", "void"};
char *ops[10] = {"+", "-", "*", "/", "<", "<=", "==", ">=", ">", "!="};

tree *maketree(int kind){
    tree *this = (tree *)malloc(sizeof(struct treenode));
    this->nodeKind = kind;
    this->numChildren = 0;
    this->val = 0;
    this->scope = -1;
    this->type = -1;
    this->sym_type = -1;
    this->lineno = yylineno;
    this->name = NULL;
    this->parent = NULL;

    for (int i = 0; i < MAXCHILDREN; i++){
        this->children[i] = NULL;
    }

    return this;
}

tree *maketreeWithVal(int kind, int val){
    tree *this = (tree *)malloc(sizeof(struct treenode));
    this->nodeKind = kind;
    this->numChildren = 0;
    this->val = val;
    this->scope = -1;
    this->type = -1;
    this->sym_type = -1;
    this->lineno = yylineno;
    this->name = NULL;
    this->parent = NULL;

    for (int i = 0; i < MAXCHILDREN; i++){
        this->children[i] = NULL;
    }

    return this;
}

void addChild(tree *parent, tree *child){
    if (parent->numChildren == MAXCHILDREN){
        printf("Cannot add child to parent node\n");
        exit(1);
    }

    nextAvailChild(parent) = child;
    if (child != NULL){
        child->parent = parent;
    }
    parent->numChildren++;
}

void printAst(tree *node, int nestLevel){
    char *nodeName = nodeNames[node->nodeKind];

    if (strcmp(nodeName, "identifier") == 0){
        if (node->val == -1)
            printf("%s,%s\n", nodeName, "undeclared variable");
        else if (node->name != NULL)
            printf("%s,%s\n", nodeName, node->name);
        else
            printf("%s,%s\n", nodeName, "unknown");
    }
    else if (strcmp(nodeName, "integer") == 0){
        printf("%s,%d\n", nodeName, node->val);
    }
    else if (strcmp(nodeName, "char") == 0){
        printf("%s,%c\n", nodeName, node->val);
    }
    else if (strcmp(nodeName, "typeSpecifier") == 0){
        printf("%s,%s\n", nodeName, typeNames[node->val]);
    }
    else if (strcmp(nodeName, "relop") == 0 || strcmp(nodeName, "mulop") == 0 || strcmp(nodeName, "addop") == 0){
        printf("%s,%s\n", nodeName, ops[node->val]);
    }
    else{
        printf("%s\n", nodeName);
    }

    int i, j;

    for (i = 0; i < node->numChildren; i++){
        for (j = 0; j < nestLevel; j++)
            printf("    ");
        printAst(getChild(node, i), nestLevel + 1);
    }
}

void flattenList(tree *list, tree *subList){
    for (int i = 0; i < subList->numChildren; i++){
        addChild(list, getChild(subList, i));
    }
}