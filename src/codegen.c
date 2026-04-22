#include "codegen.h"
#include "tree.h"
#include "strtab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables for code generation
int label_counter = 0;
FILE *output_file = NULL;

// Variable offset tracking (simple global variable approach)
typedef struct var_info
{
    char *name;
    int is_array;
    int array_size;
    struct var_info *next;
} var_info;

var_info *global_vars = NULL;

// Helper: Generate unique labels
char *generate_label()
{
    static char label[32];
    sprintf(label, "L%d", label_counter++);
    return strdup(label);
}

// Helper: Add variable to tracking
void add_variable(char *name, int is_array, int size)
{
    var_info *info = (var_info *)malloc(sizeof(var_info));
    info->name = strdup(name);
    info->is_array = is_array;
    info->array_size = size;
    info->next = global_vars;
    global_vars = info;
}

// Helper: Find variable info
var_info *find_variable(char *name)
{
    var_info *current = global_vars;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Collect all variable declarations
void collect_variables(tree *node)
{
    if (node == NULL)
        return;

    if (node->nodeKind == VARDECL)
    {
        tree *typeSpec = getChild(node, 0);
        tree *id = getChild(node, 1);

        if (node->numChildren == 2)
        {
            // Simple variable
            add_variable(id->name, 0, 0);
        }
        else if (node->numChildren == 3)
        {
            // Array
            tree *size = getChild(node, 2);
            add_variable(id->name, 1, size->val);
        }
    }

    // Recursively collect from children
    for (int i = 0; i < node->numChildren; i++)
    {
        collect_variables(getChild(node, i));
    }
}

// Generate data section
void codegen_data_section(tree *ast, FILE *output)
{
    fprintf(output, ".data\n");

    // Declare all variables
    var_info *current = global_vars;
    while (current != NULL)
    {
        if (current->is_array)
        {
            fprintf(output, "%s: .space %d  # array[%d]\n",
                    current->name, current->array_size * 4, current->array_size);
        }
        else
        {
            fprintf(output, "%s: .word 0\n", current->name);
        }
        current = current->next;
    }

    fprintf(output, "\n");
}

// Main entry point
void codegen_program(tree *ast, FILE *output)
{
    if (ast == NULL)
        return;

    output_file = output;

    // Header
    fprintf(output, "# mC Compiler - Generated MIPS Assembly\n");
    fprintf(output, "# Code Generator Phase 4\n\n");

    // Collect all variables first
    collect_variables(ast);

    // Generate data section
    codegen_data_section(ast, output);

    // Text section
    fprintf(output, ".text\n");
    fprintf(output, ".globl main\n\n");

    // Find and generate main function
    if (ast->nodeKind == PROGRAM && ast->numChildren > 0)
    {
        tree *declList = getChild(ast, 0);
        codegen_declaration_list(declList, output);
    }

    // Exit
    fprintf(output, "\n# Exit program\n");
    fprintf(output, "li $v0, 10\n");
    fprintf(output, "syscall\n");
}

// Process declaration list
void codegen_declaration_list(tree *node, FILE *output)
{
    if (node == NULL)
        return;

    if (node->nodeKind == DECLLIST)
    {
        for (int i = 0; i < node->numChildren; i++)
        {
            tree *child = getChild(node, i);
            if (child->nodeKind == DECLLIST)
            {
                codegen_declaration_list(child, output);
            }
            else if (child->nodeKind == DECL)
            {
                tree *decl = getChild(child, 0);
                if (decl->nodeKind == FUNDECL)
                {
                    codegen_function(decl, output);
                }
            }
        }
    }
}

// Generate function
void codegen_function(tree *node, FILE *output)
{
    if (node == NULL)
        return;

    tree *funcTypeName = getChild(node, 0);
    tree *funcName = getChild(funcTypeName, 1);

    fprintf(output, "%s:\n", funcName->name);

    // Find function body
    tree *funBody = NULL;
    for (int i = 0; i < node->numChildren; i++)
    {
        if (getChild(node, i)->nodeKind == FUNBODY)
        {
            funBody = getChild(node, i);
            break;
        }
    }

    if (funBody != NULL)
    {
        for (int i = 0; i < funBody->numChildren; i++)
        {
            tree *child = getChild(funBody, i);
            if (child->nodeKind == STATEMENTLIST)
            {
                codegen_statement_list(child, output);
            }
        }
    }
}

// Process statement list
void codegen_statement_list(tree *node, FILE *output)
{
    if (node == NULL)
        return;

    if (node->nodeKind == STATEMENTLIST)
    {
        for (int i = 0; i < node->numChildren; i++)
        {
            tree *child = getChild(node, i);
            if (child->nodeKind == STATEMENTLIST)
            {
                codegen_statement_list(child, output);
            }
            else if (child->nodeKind == STATEMENT)
            {
                tree *stmt = getChild(child, 0);
                codegen_statement(stmt, output);
            }
        }
    }
}

// Generate statement (LEWIS + MICHAEL)
void codegen_statement(tree *node, FILE *output)
{
    if (node == NULL)
        return;

    switch (node->nodeKind)
    {
    case ASSIGNSTMT:
        codegen_assignment(node, output);
        break;
    case CONDSTMT:
        codegen_conditional(node, output);
        break;
    case LOOPSTMT:
        codegen_loop(node, output);
        break;
    case RETURNSTMT:
        if (node->numChildren > 0)
        {
            codegen_expression(getChild(node, 0), output);
        }
        break;
    }
}

// Generate assignment
void codegen_assignment(tree *node, FILE *output)
{
    if (node == NULL)
        return;

    fprintf(output, "\n# Assignment\n");

    if (node->numChildren == 2)
    {
        tree *var = getChild(node, 0);
        tree *expr = getChild(node, 1);

        // Evaluate expression (result in $t0)
        codegen_expression(expr, output);

        // Store to variable
        if (var->nodeKind == VAR && var->numChildren > 0)
        {
            tree *id = getChild(var, 0);
            var_info *info = find_variable(id->name);

            if (info != NULL)
            {
                if (var->numChildren == 1)
                {
                    // Simple variable
                    fprintf(output, "sw $t0, %s\n", id->name);
                }
                else if (var->numChildren == 2)
                {
                    // Array element: var[index]
                    tree *index_expr = getChild(var, 1);

                    // Save current $t0 (the value to store)
                    fprintf(output, "move $t9, $t0\n");

                    // Evaluate index
                    codegen_addExpr(index_expr, output);

                    // Calculate address: base + index*4
                    fprintf(output, "sll $t0, $t0, 2  # index * 4\n");
                    fprintf(output, "la $t1, %s\n", id->name);
                    fprintf(output, "add $t1, $t1, $t0\n");
                    fprintf(output, "sw $t9, 0($t1)\n");
                }
            }
        }
    }
}

// Generate expression
void codegen_expression(tree *node, FILE *output)
{
    if (node == NULL)
        return;

    if (node->nodeKind == EXPRESSION)
    {
        if (node->numChildren == 1)
        {
            codegen_addExpr(getChild(node, 0), output);
        }
        else if (node->numChildren == 3)
        {
            // Relational: expr relop addExpr
            tree *left = getChild(node, 0);
            tree *op = getChild(node, 1);
            tree *right = getChild(node, 2);

            codegen_expression(left, output);
            fprintf(output, "move $t1, $t0\n");

            codegen_addExpr(right, output);
            fprintf(output, "move $t2, $t0\n");

            switch (op->val)
            {
            case LT_OP:
                fprintf(output, "slt $t0, $t1, $t2\n");
                break;
            case LTE_OP:
                fprintf(output, "sle $t0, $t1, $t2\n");
                break;
            case GT_OP:
                fprintf(output, "sgt $t0, $t1, $t2\n");
                break;
            case GTE_OP:
                fprintf(output, "sge $t0, $t1, $t2\n");
                break;
            case EQ_OP:
                fprintf(output, "seq $t0, $t1, $t2\n");
                break;
            case NEQ_OP:
                fprintf(output, "sne $t0, $t1, $t2\n");
                break;
            }
        }
    }
}

// Generate additive expression
void codegen_addExpr(tree *node, FILE *output)
{
    if (node == NULL)
        return;

    if (node->nodeKind == ADDEXPR)
    {
        if (node->numChildren == 1)
        {
            codegen_term(getChild(node, 0), output);
        }
        else if (node->numChildren == 3)
        {
            tree *left = getChild(node, 0);
            tree *op = getChild(node, 1);
            tree *right = getChild(node, 2);

            codegen_addExpr(left, output);
            fprintf(output, "move $t1, $t0\n");

            codegen_term(right, output);
            fprintf(output, "move $t2, $t0\n");

            if (op->val == 0)
            {
                fprintf(output, "add $t0, $t1, $t2\n");
            }
            else
            {
                fprintf(output, "sub $t0, $t1, $t2\n");
            }
        }
    }
}

// Generate term
void codegen_term(tree *node, FILE *output)
{
    if (node == NULL)
        return;

    if (node->nodeKind == TERM)
    {
        if (node->numChildren == 1)
        {
            codegen_factor(getChild(node, 0), output);
        }
        else if (node->numChildren == 3)
        {
            tree *left = getChild(node, 0);
            tree *op = getChild(node, 1);
            tree *right = getChild(node, 2);

            codegen_term(left, output);
            fprintf(output, "move $t1, $t0\n");

            codegen_factor(right, output);
            fprintf(output, "move $t2, $t0\n");

            if (op->val == 2)
            { // MUL
                fprintf(output, "mul $t0, $t1, $t2\n");
            }
            else
            { // DIV
                fprintf(output, "div $t1, $t2\n");
                fprintf(output, "mflo $t0\n");
            }
        }
    }
}

// Load factor
void codegen_factor(tree *node, FILE *output)
{
    if (node == NULL)
        return;

    if (node->nodeKind == FACTOR && node->numChildren > 0)
    {
        tree *content = getChild(node, 0);

        switch (content->nodeKind)
        {
        case INTEGER:
            fprintf(output, "li $t0, %d\n", content->val);
            break;
        case CHAR_NODE:
            fprintf(output, "li $t0, %d\n", (int)content->val);
            break;
        case VAR:
            codegen_var(content, output);
            break;
        case EXPRESSION:
            codegen_expression(content, output);
            break;
        }
    }
}

// Load variable
void codegen_var(tree *node, FILE *output)
{
    if (node == NULL || node->numChildren == 0)
        return;

    tree *id = getChild(node, 0);
    var_info *info = find_variable(id->name);

    if (info != NULL)
    {
        if (node->numChildren == 1)
        {
            // Simple variable
            fprintf(output, "lw $t0, %s\n", id->name);
        }
        else if (node->numChildren == 2)
        {
            // Array element
            tree *index_expr = getChild(node, 1);

            // Evaluate index
            codegen_addExpr(index_expr, output);

            // Calculate address
            fprintf(output, "sll $t0, $t0, 2  # index * 4\n");
            fprintf(output, "la $t1, %s\n", id->name);
            fprintf(output, "add $t1, $t1, $t0\n");
            fprintf(output, "lw $t0, 0($t1)\n");
        }
    }
}

// MICHAEL's stubs - Implementation required for control flow constructs
void codegen_conditional(tree *node, FILE *output)
{
    fprintf(output, "# Conditional (TODO: Michael)\n");
}

void codegen_loop(tree *node, FILE *output)
{
    fprintf(output, "# Loop (TODO: Michael)\n");
}