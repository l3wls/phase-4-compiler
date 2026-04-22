#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tree.h>
#include <strtab.h>
#include "codegen.h"

extern FILE *yyin;
extern int yyparse(void);

void printhelp()
{
    printf("Usage: mcc [--ast] [--sym] [-h|--help] FILE\n");
    printf("\t--ast:\t\tPrint a textual representation of the constructed abstract syntax tree.\n");
    printf("\t--sym:\t\tPrint a textual representation of the constructed symbol table.\n");
    printf("\t-h,--help:\tPrint this help information and exit.\n\n");
}

int main(int argc, char *argv[])
{
    int p_ast = 0;
    int p_symtab = 0;

    // Skip first arg (program name), then check all but last for options.
    for (int i = 1; i < argc - 1; i++)
    {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
        {
            printhelp();
            return 0;
        }
        else if (strcmp(argv[i], "--ast") == 0)
        {
            p_ast = 1;
        }
        else if (strcmp(argv[i], "--sym") == 0)
        {
            p_symtab = 1;
        }
        else
        {
            printhelp();
            return 0;
        }
    }

    yyin = fopen(argv[argc - 1], "r");
    if (!yyin)
    {
        printf("error: unable to read source file %s\n", argv[argc - 1]);
        return -1;
    }

    init_symbol_table();

    if (!yyparse())
    {
        semantic_analysis(ast);
        printf("Compilation finished.\n\n");

        // Generate assembly code
        char output_filename[256];
        strcpy(output_filename, argv[argc - 1]);
        char *dot = strrchr(output_filename, '.');
        if (dot)
            *dot = '\0';
        strcat(output_filename, ".s");

        FILE *output = fopen(output_filename, "w");
        if (output)
        {
            codegen_program(ast, output);
            fclose(output);
            printf("Assembly code generated: %s\n\n", output_filename);
        }

        if (p_ast)
            printAst(ast, 1);
        if (p_symtab)
            print_sym_tab();
    }
    return 0;
}