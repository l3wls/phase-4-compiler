%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "strtab.h"

extern int yylineno;
extern int yylex(void);
extern char* yytext;
extern int yycol;
extern char *scan_err;

int yywarning(char *msg);
int yyerror(char *msg);

extern tree *ast;

int current_function_index = -1;
int current_function_param_count = 0;

%}

/* Union describes yylval fields */
%union {
    int value;
    struct treenode *node;
    char *strval;
}

/* ============ TOKEN DECLARATIONS ============ */

/* Tokens with values */
%token <strval> ID STRCONST
%token <value> INTCONST CHARCONST

/* Keywords */
%token KWD_IF KWD_ELSE KWD_WHILE 
%token KWD_INT KWD_CHAR 
%token KWD_RETURN KWD_VOID

/* Operators */
%token OPER_ADD OPER_SUB OPER_MUL OPER_DIV OPER_MOD
%token OPER_LT OPER_GT OPER_LTE OPER_GTE OPER_EQ OPER_NEQ
%token OPER_ASGN
%token OPER_AT OPER_INC OPER_DEC OPER_AND OPER_OR OPER_NOT

/* Punctuation */
%token LSQ_BRKT RSQ_BRKT 
%token LCRLY_BRKT RCRLY_BRKT 
%token LPAREN RPAREN
%token COMMA SEMICLN

/* Error token */
%token ERROR

/* ============ NON-TERMINAL TYPE DECLARATIONS ============ */

%type <node> program declList decl varDecl typeSpecifier funDecl
%type <node> formalDeclList formalDecl funBody localDeclList
%type <node> statementList statement compoundStmt assignStmt
%type <node> condStmt loopStmt returnStmt
%type <node> var expression addExpr term factor
%type <node> funcCallExpr argList relop addop mulop
%type <node> funcTypeName arrayDecl

%start program

%nonassoc LOWER_THAN_ELSE
%nonassoc KWD_ELSE

%%

/* ============ GRAMMAR RULES ============ */

program : declList
    {
        tree *progNode = maketree(PROGRAM);
        addChild(progNode, $1);
        ast = progNode;
        $$ = progNode;
    }
    ;

declList : decl
    {
        tree* declListNode = maketree(DECLLIST);
        addChild(declListNode, $1);
        $$ = declListNode;
    }
    | declList decl
    {
        tree* declListNode = maketree(DECLLIST);
        addChild(declListNode, $1);
        addChild(declListNode, $2);
        $$ = declListNode;
    }
    ;

decl : varDecl
    {
        tree* declNode = maketree(DECL);
        addChild(declNode, $1);
        $$ = declNode;
    }
    | funDecl
    {
        tree* declNode = maketree(DECL);
        addChild(declNode, $1);
        $$ = declNode;
    }
    ;

varDecl : typeSpecifier ID SEMICLN
    {
        tree* varDeclNode = maketree(VARDECL);
        addChild(varDeclNode, $1);
        
        tree* idNode = maketree(IDENTIFIER);
        idNode->name = strdup($2);
        addChild(varDeclNode, idNode);
        
        ST_insert($2, $1->val, SCALAR, NULL);
        
        $$ = varDeclNode;
    }
    | typeSpecifier ID LSQ_BRKT INTCONST RSQ_BRKT SEMICLN
    {
        tree* varDeclNode = maketree(VARDECL);
        addChild(varDeclNode, $1);

        tree* idNode = maketree(IDENTIFIER);
        idNode->name = strdup($2);
        addChild(varDeclNode, idNode);

        tree* sizeNode = maketreeWithVal(INTEGER, $4);
        addChild(varDeclNode, sizeNode);

        int array_index = -1;
        ST_insert($2, $1->val, ARRAY, &array_index);

        if (array_index != -1 && current_scope->strTable[array_index] != NULL) {
            current_scope->strTable[array_index]->size = $4;
        }

        if ($4 == 0){
            printf("error: line %d: Array variable declared with size of zero.\n", yylineno);
        }

        $$ = varDeclNode;
    }
    ;

typeSpecifier : KWD_INT
    {
        $$ = maketreeWithVal(TYPESPEC, INT_TYPE);
    }
    | KWD_CHAR
    {
        $$ = maketreeWithVal(TYPESPEC, CHAR_TYPE);
    }
    | KWD_VOID
    {
        $$ = maketreeWithVal(TYPESPEC, VOID_TYPE);
    }
    ;

funDecl : funcTypeName LPAREN formalDeclList RPAREN funBody
    {
        tree* funDeclNode = maketree(FUNDECL);
        addChild(funDeclNode, $1);
        addChild(funDeclNode, $3);
        addChild(funDeclNode, $5);

        if (current_function_index != -1) {
            connect_params(current_function_index, current_function_param_count);
        }

        up_scope();  // exit function scope
        current_scope_name = NULL;
        current_function_index = -1;
        current_function_param_count = 0;

        $$ = funDeclNode;
    }
    | funcTypeName LPAREN RPAREN funBody
    {
        tree* funDeclNode = maketree(FUNDECL);
        addChild(funDeclNode, $1);
        addChild(funDeclNode, $4);

        if (current_function_index != -1) {
            connect_params(current_function_index, 0);
        }

        up_scope();  // exit function scope
        current_scope_name = NULL;
        current_function_index = -1;
        current_function_param_count = 0;

        $$ = funDeclNode;
    }
    ;

funcTypeName : typeSpecifier ID
    {
        tree* funcTypeNameNode = maketree(FUNCTYPENAME);
        addChild(funcTypeNameNode, $1);

        tree* idNode = maketree(IDENTIFIER);
        idNode->name = strdup($2);
        addChild(funcTypeNameNode, idNode);

        int func_index = -1;
        ST_insert($2, $1->val, FUNCTION, &func_index);

        current_function_index = func_index;
        current_function_param_count = 0;
        current_scope_name = strdup($2);

        working_list_head = NULL;
        working_list_end = NULL;

        new_scope();

        $$ = funcTypeNameNode;
    }
    ;

formalDeclList : formalDecl
    {
        tree* formalDeclListNode = maketree(FORMALDECLLIST);
        addChild(formalDeclListNode, $1);
        $$ = formalDeclListNode;
    }
    | formalDecl COMMA formalDeclList
    {
        tree* formalDeclListNode = maketree(FORMALDECLLIST);
        addChild(formalDeclListNode, $1);
        addChild(formalDeclListNode, $3);
        $$ = formalDeclListNode;
    }
    ;

formalDecl : typeSpecifier ID
    {
        tree* formalDeclNode = maketree(FORMALDECL);
        addChild(formalDeclNode, $1);

        tree* idNode = maketree(IDENTIFIER);
        idNode->name = strdup($2);
        addChild(formalDeclNode, idNode);

        ST_insert($2, $1->val, SCALAR, NULL);
        add_param($1->val, SCALAR);
        current_function_param_count++;

        $$ = formalDeclNode;
    }
    | typeSpecifier ID arrayDecl
    {
        tree* formalDeclNode = maketree(FORMALDECL);
        addChild(formalDeclNode, $1);

        tree* idNode = maketree(IDENTIFIER);
        idNode->name = strdup($2);
        addChild(formalDeclNode, idNode);

        addChild(formalDeclNode, $3);

        ST_insert($2, $1->val, ARRAY, NULL);
        add_param($1->val, ARRAY);
        current_function_param_count++;

        $$ = formalDeclNode;
    }
    ;

arrayDecl : LSQ_BRKT RSQ_BRKT
    {
        $$ = maketree(ARRAYDECL);
    }
    ;

funBody : LCRLY_BRKT localDeclList statementList RCRLY_BRKT
    {
        tree* funBodyNode = maketree(FUNBODY);
        if ($2 != NULL) addChild(funBodyNode, $2);
        if ($3 != NULL) addChild(funBodyNode, $3);
        $$ = funBodyNode;
    }
    ;

localDeclList :
    {
        $$ = NULL;
    }
    | varDecl localDeclList
    {
        tree* localDeclListNode = maketree(LOCALDECLLIST);
        addChild(localDeclListNode, $1);
        if ($2 != NULL) addChild(localDeclListNode, $2);
        $$ = localDeclListNode;
    }
    ;

statementList :
    {
        $$ = NULL;
    }
    | statement statementList
    {
        tree* stmtListNode = maketree(STATEMENTLIST);
        addChild(stmtListNode, $1);
        if ($2 != NULL) addChild(stmtListNode, $2);
        $$ = stmtListNode;
    }
    ;

statement : assignStmt
    {
        tree* stmtNode = maketree(STATEMENT);
        addChild(stmtNode, $1);
        $$ = stmtNode;
    }
    | compoundStmt
    {
        tree* stmtNode = maketree(STATEMENT);
        addChild(stmtNode, $1);
        $$ = stmtNode;
    }
    | condStmt
    {
        tree* stmtNode = maketree(STATEMENT);
        addChild(stmtNode, $1);
        $$ = stmtNode;
    }
    | loopStmt
    {
        tree* stmtNode = maketree(STATEMENT);
        addChild(stmtNode, $1);
        $$ = stmtNode;
    }
    | returnStmt
    {
        tree* stmtNode = maketree(STATEMENT);
        addChild(stmtNode, $1);
        $$ = stmtNode;
    }
    ;

compoundStmt : LCRLY_BRKT statementList RCRLY_BRKT
    {
        tree* compStmtNode = maketree(COMPOUNDSTMT);
        if ($2 != NULL) addChild(compStmtNode, $2);
        $$ = compStmtNode;
    }
    ;

assignStmt : var OPER_ASGN expression SEMICLN
    {
        tree* assignNode = maketree(ASSIGNSTMT);
        addChild(assignNode, $1);
        addChild(assignNode, $3);
        $$ = assignNode;
    }
    | expression SEMICLN
    {
        tree* assignNode = maketree(ASSIGNSTMT);
        addChild(assignNode, $1);
        $$ = assignNode;
    }
    ;

condStmt : KWD_IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE
    {
        tree* condNode = maketree(CONDSTMT);
        addChild(condNode, $3);
        addChild(condNode, $5);
        $$ = condNode;
    }
    | KWD_IF LPAREN expression RPAREN statement KWD_ELSE statement
    {
        tree* condNode = maketree(CONDSTMT);
        addChild(condNode, $3);
        addChild(condNode, $5);
        addChild(condNode, $7);
        $$ = condNode;
    }
    ;

loopStmt : KWD_WHILE LPAREN expression RPAREN statement
    {
        tree* loopNode = maketree(LOOPSTMT);
        addChild(loopNode, $3);
        addChild(loopNode, $5);
        $$ = loopNode;
    }
    ;

returnStmt : KWD_RETURN SEMICLN
    {
        $$ = maketree(RETURNSTMT);
    }
    | KWD_RETURN expression SEMICLN
    {
        tree* returnNode = maketree(RETURNSTMT);
        addChild(returnNode, $2);
        $$ = returnNode;
    }
    ;

var : ID
    {
        tree* varNode = maketree(VAR);
        tree* idNode = maketree(IDENTIFIER);
        idNode->name = strdup($1);

        symEntry* entry = ST_lookup_silent($1);
        if (entry == NULL) {
            idNode->val = -1;
        } else {
            idNode->type = entry->data_type;
            idNode->sym_type = entry->symbol_type;
            idNode->scope = entry->size;
        }

        addChild(varNode, idNode);
        $$ = varNode;
    }
    | ID LSQ_BRKT addExpr RSQ_BRKT
    {
        tree* varNode = maketree(VAR);
        tree* idNode = maketree(IDENTIFIER);
        idNode->name = strdup($1);

        symEntry* entry = ST_lookup_silent($1);
        if (entry == NULL) {
            idNode->val = -1;
        } else {
            idNode->type = entry->data_type;
            idNode->sym_type = entry->symbol_type;
            idNode->scope = entry->size;
        }

        addChild(varNode, idNode);
        addChild(varNode, $3);
        $$ = varNode;
    }
    ;

expression : addExpr
    {
        tree* exprNode = maketree(EXPRESSION);
        addChild(exprNode, $1);
        $$ = exprNode;
    }
    | expression relop addExpr
    {
        tree* exprNode = maketree(EXPRESSION);
        addChild(exprNode, $1);
        addChild(exprNode, $2);
        addChild(exprNode, $3);
        $$ = exprNode;
    }
    ;

relop : OPER_LTE  { $$ = maketreeWithVal(RELOP, LTE_OP); }
    | OPER_LT     { $$ = maketreeWithVal(RELOP, LT_OP); }
    | OPER_GT     { $$ = maketreeWithVal(RELOP, GT_OP); }
    | OPER_GTE    { $$ = maketreeWithVal(RELOP, GTE_OP); }
    | OPER_EQ     { $$ = maketreeWithVal(RELOP, EQ_OP); }
    | OPER_NEQ    { $$ = maketreeWithVal(RELOP, NEQ_OP); }
    ;

addExpr : term
    {
        tree* addExprNode = maketree(ADDEXPR);
        addChild(addExprNode, $1);
        $$ = addExprNode;
    }
    | addExpr addop term
    {
        tree* addExprNode = maketree(ADDEXPR);
        addChild(addExprNode, $1);
        addChild(addExprNode, $2);
        addChild(addExprNode, $3);
        $$ = addExprNode;
    }
    ;

addop : OPER_ADD  { $$ = maketreeWithVal(ADDOP, 0); }
    | OPER_SUB    { $$ = maketreeWithVal(ADDOP, 1); }
    ;

term : factor
    {
        tree* termNode = maketree(TERM);
        addChild(termNode, $1);
        $$ = termNode;
    }
    | term mulop factor
    {
        tree* termNode = maketree(TERM);
        addChild(termNode, $1);
        addChild(termNode, $2);
        addChild(termNode, $3);
        $$ = termNode;
    }
    ;

mulop : OPER_MUL  { $$ = maketreeWithVal(MULOP, 2); }
    | OPER_DIV    { $$ = maketreeWithVal(MULOP, 3); }
    ;

factor : LPAREN expression RPAREN
    {
        tree* factorNode = maketree(FACTOR);
        addChild(factorNode, $2);
        $$ = factorNode;
    }
    | var
    {
        tree* factorNode = maketree(FACTOR);
        addChild(factorNode, $1);
        $$ = factorNode;
    }
    | funcCallExpr
    {
        tree* factorNode = maketree(FACTOR);
        addChild(factorNode, $1);
        $$ = factorNode;
    }
    | INTCONST
    {
        tree* factorNode = maketree(FACTOR);
        tree* intNode = maketreeWithVal(INTEGER, $1);
        addChild(factorNode, intNode);
        $$ = factorNode;
    }
    | CHARCONST
    {
        tree* factorNode = maketree(FACTOR);
        tree* charNode = maketreeWithVal(CHAR_NODE, $1);
        addChild(factorNode, charNode);
        $$ = factorNode;
    }
    | STRCONST
    {
        tree* factorNode = maketree(FACTOR);
        tree* strNode = maketree(STRING_NODE);
        strNode->name = strdup($1);
        addChild(factorNode, strNode);
        $$ = factorNode;
    }
    ;

funcCallExpr : ID LPAREN argList RPAREN
    {
        tree* funcCallNode = maketree(FUNCALLEXPR);
        tree* idNode = maketree(IDENTIFIER);
        idNode->name = strdup($1);

        symEntry* entry = ST_lookup_silent($1);
        if (entry == NULL || entry->symbol_type != FUNCTION) {
            printf("error: line %d: Undefined function\n", yylineno);
            idNode->val = -1;
        } else {
            idNode->type = entry->data_type;
            idNode->sym_type = entry->symbol_type;
        }

        addChild(funcCallNode, idNode);
        addChild(funcCallNode, $3);
        $$ = funcCallNode;
    }
    | ID LPAREN RPAREN
    {
        tree* funcCallNode = maketree(FUNCALLEXPR);
        tree* idNode = maketree(IDENTIFIER);
        idNode->name = strdup($1);

        symEntry* entry = ST_lookup_silent($1);
        if (entry == NULL || entry->symbol_type != FUNCTION) {
            printf("error: line %d: Undefined function\n", yylineno);
            idNode->val = -1;
        } else {
            idNode->type = entry->data_type;
            idNode->sym_type = entry->symbol_type;
        }

        addChild(funcCallNode, idNode);
        $$ = funcCallNode;
    }
    ;

argList : expression
    {
        tree* argListNode = maketree(ARGLIST);
        addChild(argListNode, $1);
        $$ = argListNode;
    }
    | argList COMMA expression
    {
        tree* argListNode = maketree(ARGLIST);
        addChild(argListNode, $1);
        addChild(argListNode, $3);
        $$ = argListNode;
    }
    ;

%%

int yywarning(char *msg) {
    printf("warning: line %d: %s\n", yylineno, msg);
    return 0;
}

int yyerror(char *msg) {
    if (scan_err != NULL) {
        printf("error: line %d, col %d: %s\n", yylineno, yycol, scan_err);
        scan_err = NULL;
    } else {
        printf("error: line %d: %s\n", yylineno, msg);
    }
    return 0;
}