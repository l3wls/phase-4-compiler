#ifndef CODEGEN_H
#define CODEGEN_H

#include "tree.h"
#include "strtab.h"
#include <stdio.h>

// Main entry point
void codegen_program(tree *ast, FILE *output);

// Helper functions
void codegen_declaration_list(tree *node, FILE *output);
void codegen_function(tree *node, FILE *output);
void codegen_statement_list(tree *node, FILE *output);
void codegen_statement(tree *node, FILE *output);

// functions - Expressions & Assignments
void codegen_expression(tree *node, FILE *output);
void codegen_addExpr(tree *node, FILE *output);
void codegen_term(tree *node, FILE *output);
void codegen_factor(tree *node, FILE *output);
void codegen_var(tree *node, FILE *output);
void codegen_assignment(tree *node, FILE *output);

// functions - Control Flow
void codegen_statement_node(tree *node, FILE *output);
void codegen_conditional(tree *node, FILE *output);
void codegen_loop(tree *node, FILE *output);

// Data section generation
void codegen_data_section(tree *ast, FILE *output);

// Helpers
char *generate_label();

#endif