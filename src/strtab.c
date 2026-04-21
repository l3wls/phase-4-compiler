#include "strtab.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;

// Global variables (just declare, don't initialize here)
param *working_list_head;
param *working_list_end;
table_node *current_scope;
char *current_scope_name;

// Hash function (djb2)
unsigned long hash(char *str){
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash % MAXIDS;
}

// Initialize the global scope (call this at program start)
void init_symbol_table(){
    // Initialize global pointers
    working_list_head = NULL;
    working_list_end = NULL;
    current_scope_name = NULL;
    // Create global scope node
    current_scope = (table_node *)malloc(sizeof(table_node));
    current_scope->numChildren = 0;
    current_scope->parent = NULL;
    current_scope->first_child = NULL;
    current_scope->last_child = NULL;
    current_scope->next = NULL;

    // Initialize all symbol table entries to NULL
    for (int i = 0; i < MAXIDS; i++){
        current_scope->strTable[i] = NULL;
    }
}

// Insert symbol into current scope
int ST_insert(char *id, int data_type, int symbol_type, int *scope){
    if (current_scope == NULL){
        init_symbol_table();
    }

    unsigned long h = hash(id);
    unsigned long original_h = h;

    // Linear probing to find empty slot or existing entry
    while (current_scope->strTable[h] != NULL){
        // Check if already declared in current scope
        if (strcmp(current_scope->strTable[h]->id, id) == 0){
            // Symbol already declared in this scope!
            printf("error: line %d: Symbol declared multiple times.\n", yylineno);
            return -1;
        }
        h = (h + 1) % MAXIDS;

        // If we've looped back, table is full
        if (h == original_h){
            printf("error: Symbol table full\n");
            return -1;
        }
    }
    // Create new entry
    symEntry *entry = (symEntry *)malloc(sizeof(symEntry));
    entry->id = strdup(id);
    entry->scope = (current_scope_name == NULL) ? strdup("") : strdup(current_scope_name);
    entry->data_type = data_type;
    entry->symbol_type = symbol_type;
    entry->size = 0;
    entry->params = NULL;
    current_scope->strTable[h] = entry;

    if (scope != NULL){
        *scope = h; // Return the hash index
    }
    return h;
}

// Lookup symbol (checks current scope, then parent scopes) - SILENT version
symEntry *ST_lookup_silent(char *id){
    if (current_scope == NULL){
        return NULL;
    }

    table_node *scope = current_scope;

    // Search current scope and all parent scopes
    while (scope != NULL){
        unsigned long h = hash(id);
        unsigned long original_h = h;

        while (scope->strTable[h] != NULL){
            if (strcmp(scope->strTable[h]->id, id) == 0){
                return scope->strTable[h];
            }
            h = (h + 1) % MAXIDS;
            if (h == original_h)
                break; // Looped around
        }
        // Move to parent scope
        scope = scope->parent;
    }
    // Not found - return NULL silently
    return NULL;
}

// Lookup symbol from root scope (for semantic analysis)
symEntry *ST_lookup_from_root(char *id, table_node *scope_node){
    if (scope_node == NULL){
        return NULL;
    }
    // Search current scope
    unsigned long h = hash(id);
    unsigned long original_h = h;

    while (scope_node->strTable[h] != NULL){
        if (strcmp(scope_node->strTable[h]->id, id) == 0){
            return scope_node->strTable[h];
        }
        h = (h + 1) % MAXIDS;
        if (h == original_h)
            break;
    }
    // Search children recursively
    table_node *child = scope_node->first_child;
    while (child != NULL){
        symEntry *result = ST_lookup_from_root(id, child);
        if (result != NULL){
            return result;
        }
        child = child->next;
    }
    return NULL;
}

// Get root of scope tree
table_node *get_root_scope(){
    table_node *root = current_scope;
    while (root != NULL && root->parent != NULL){
        root = root->parent;
    }
    return root;
}

// Lookup symbol with error message (for parser use)
symEntry *ST_lookup(char *id){
    symEntry *result = ST_lookup_silent(id);

    if (result == NULL){
        printf("error: line %d: Undeclared variable\n", yylineno);
    }
    return result;
}

// Add parameter to working list (called during parsing)
void add_param(int data_type, int symbol_type){
    param *new_param = (param *)malloc(sizeof(param));
    new_param->data_type = data_type;
    new_param->symbol_type = symbol_type;
    new_param->next = NULL;

    if (working_list_head == NULL){
        working_list_head = new_param;
        working_list_end = new_param;
    }
    else{
        working_list_end->next = new_param;
        working_list_end = new_param;
    }
}

// Connect parameters to function (called after function header)
void connect_params(int index, int num_params){
    if (current_scope->parent == NULL){
        printf("error: Cannot connect params, no parent scope\n");
        return;
    }
    symEntry *func = current_scope->parent->strTable[index];
    if (func == NULL){
        printf("error: Function entry not found\n");
        return;
    }
    func->params = working_list_head;
    func->size = num_params;
    // Reset working list
    working_list_head = NULL;
    working_list_end = NULL;
}

// Create new scope (entering function)
void new_scope(){
    table_node *new_node = (table_node *)malloc(sizeof(table_node));
    new_node->numChildren = 0;
    new_node->parent = current_scope;
    new_node->first_child = NULL;
    new_node->last_child = NULL;
    new_node->next = NULL;

    // Initialize symbol table
    for (int i = 0; i < MAXIDS; i++){
        new_node->strTable[i] = NULL;
    }
    // Link to parent
    if (current_scope->first_child == NULL){
        current_scope->first_child = new_node;
        current_scope->last_child = new_node;
    }
    else{
        current_scope->last_child->next = new_node;
        current_scope->last_child = new_node;
    }
    current_scope->numChildren++;
    // Move into new scope
    current_scope = new_node;
}

// Exit scope (leaving function)
void up_scope(){
    if (current_scope != NULL && current_scope->parent != NULL){
        current_scope = current_scope->parent;
    }
}

// Get symbol ID by index (used by tree.c)
char *get_symbol_id(int index){
    if (index < 0 || index >= MAXIDS){
        return "unknown";
    }
    // Try to find in current scope and parents
    table_node *scope = current_scope;
    while (scope != NULL){
        if (scope->strTable[index] != NULL){
            return scope->strTable[index]->id;
        }
        scope = scope->parent;
    }
    return "unknown";
}

// Helper to print a scope recursively
void print_scope(table_node *scope, int level){
    if (scope == NULL)
        return;

    // Print scope header
    for (int i = 0; i < level; i++)
        printf("  ");
    printf("Scope (level %d):\n", level);

    // Print symbols in this scope
    for (int i = 0; i < MAXIDS; i++){
        if (scope->strTable[i] != NULL){
            symEntry *entry = scope->strTable[i];
            for (int j = 0; j < level + 1; j++)
                printf("  ");

            printf("%s: ", entry->id);

            // Print type
            if (entry->data_type == INT_TYPE)
                printf("int");
            else if (entry->data_type == CHAR_TYPE)
                printf("char");
            else if (entry->data_type == VOID_TYPE)
                printf("void");
            // Print symbol type
            if (entry->symbol_type == SCALAR){
                printf(" (scalar)\n");
            }
            else if (entry->symbol_type == ARRAY){
                printf(" (array[%d])\n", entry->size);
            }
            else if (entry->symbol_type == FUNCTION){
                printf(" (function, %d params)\n", entry->size);
                // Print parameters
                param *p = entry->params;
                int param_num = 1;
                while (p != NULL){
                    for (int j = 0; j < level + 2; j++)
                        printf("  ");
                    printf("param %d: ", param_num++);
                    if (p->data_type == INT_TYPE)
                        printf("int");
                    else if (p->data_type == CHAR_TYPE)
                        printf("char");
                    else if (p->data_type == VOID_TYPE)
                        printf("void");
                    if (p->symbol_type == ARRAY)
                        printf("[]");
                    printf("\n");
                    p = p->next;
                }
            }
        }
    }

    // Print child scopes
    table_node *child = scope->first_child;
    while (child != NULL){
        print_scope(child, level + 1);
        child = child->next;
    }
}

// Print symbol table (used by driver.c with --sym flag)
void print_sym_tab(){
    printf("\n=== SYMBOL TABLE ===\n");
    print_scope(get_root_scope(), 0);
}

/* ========== SEMANTIC ANALYSIS FUNCTIONS ========== */

// Helpers

static void check_undeclared_vars_rec(tree *node, int inside_func_args){
    if (node == NULL)
        return;

    if (node->nodeKind == VAR && node->numChildren > 0){
        tree *id = getChild(node, 0);
        if (!inside_func_args && id != NULL && id->nodeKind == IDENTIFIER && id->val == -1){
            printf("error: line %d: Undeclared variable\n", node->lineno);
        }
    }

    if (node->nodeKind == FUNCALLEXPR){
        if (node->numChildren >= 2){
            check_undeclared_vars_rec(getChild(node, 1), 1);
        }
        return;
    }

    for (int i = 0; i < node->numChildren; i++){
        check_undeclared_vars_rec(getChild(node, i), inside_func_args);
    }
}

static int eval_const_int_expr(tree *node, int *out){
    if (node == NULL) return 0;

    if (node->nodeKind == EXPRESSION){
        if (node->numChildren == 1)
            return eval_const_int_expr(getChild(node, 0), out);
        return 0;
    }

    if (node->nodeKind == ADDEXPR){
        if (node->numChildren == 1)
            return eval_const_int_expr(getChild(node, 0), out);

        if (node->numChildren == 3){
            int left, right;
            if (!eval_const_int_expr(getChild(node, 0), &left)) return 0;
            if (!eval_const_int_expr(getChild(node, 2), &right)) return 0;

            tree *op = getChild(node, 1);
            if (op->val == 0) *out = left + right;
            else if (op->val == 1) *out = left - right;
            else return 0;

            return 1;
        }
        return 0;
    }

    if (node->nodeKind == TERM){
        if (node->numChildren == 1)
            return eval_const_int_expr(getChild(node, 0), out);

        if (node->numChildren == 3){
            int left, right;
            if (!eval_const_int_expr(getChild(node, 0), &left)) return 0;
            if (!eval_const_int_expr(getChild(node, 2), &right)) return 0;

            tree *op = getChild(node, 1);
            if (op->val == 2) *out = left * right;
            else if (op->val == 3){
                if (right == 0) return 0;
                *out = left / right;
            }
            else return 0;

            return 1;
        }
        return 0;
    }

    if (node->nodeKind == FACTOR){
        if (node->numChildren == 1)
            return eval_const_int_expr(getChild(node, 0), out);
        return 0;
    }

    if (node->nodeKind == INTEGER){
        *out = node->val;
        return 1;
    }

    return 0;
}

tree *unwrap_simple_rhs(tree *node){
    if (node == NULL) return NULL;

    if (node->nodeKind == EXPRESSION && node->numChildren == 1)
        return unwrap_simple_rhs(getChild(node, 0));

    if (node->nodeKind == ADDEXPR && node->numChildren == 1)
        return unwrap_simple_rhs(getChild(node, 0));

    if (node->nodeKind == TERM && node->numChildren == 1)
        return unwrap_simple_rhs(getChild(node, 0));

    if (node->nodeKind == FACTOR && node->numChildren == 1)
        return unwrap_simple_rhs(getChild(node, 0));

    if (node->nodeKind == VAR ||
        node->nodeKind == FUNCALLEXPR ||
        node->nodeKind == INTEGER ||
        node->nodeKind == CHAR_NODE ||
        node->nodeKind == STRING_NODE){
        return node;
    }

    return NULL;
}

// Check for type mismatch in assignment statements
void check_type_mismatch(tree *node){
    if (node == NULL)
        return;

    if (node->nodeKind == ASSIGNSTMT && node->numChildren == 2){
        tree *lhs = getChild(node, 0);
        tree *rhs = getChild(node, 1);

        int lhs_type = -1;
        int rhs_type = -1;

        if (lhs->nodeKind == VAR && lhs->numChildren > 0){
            tree *lhs_id = getChild(lhs, 0);
            if (lhs_id != NULL && lhs_id->nodeKind == IDENTIFIER && lhs_id->val != -1){
                lhs_type = lhs_id->type;
            }
        }

        rhs_type = get_expr_type(rhs);

        if (lhs_type != -1 && rhs_type != -1){
            if (rhs_type == -2 || lhs_type != rhs_type){
                printf("error: line %d: Type mismatch in assignment.\n", node->lineno);
            }
        }
    }

    for (int i = 0; i < node->numChildren; i++){
        check_type_mismatch(getChild(node, i));
    }
}

// Check for array indexing errors
void check_array_indexing(tree *node){
    if (node == NULL)
        return;

    if (node->nodeKind == VAR && node->numChildren == 2){
        tree *id_node = getChild(node, 0);
        tree *index_expr = getChild(node, 1);

        if (id_node->nodeKind == IDENTIFIER && id_node->val != -1){
            if (id_node->sym_type != ARRAY){
                printf("error: line %d: Non-array identifier used as an array.\n", node->lineno);
            }
            else {
                int index_type = get_expr_type(index_expr);

                if (index_type != -1 && index_type != INT_TYPE){
                    printf("error: line %d: Array indexed using non-integer expression.\n", node->lineno);
                }
                else if (index_type == INT_TYPE){
                    int index_val = 0;
                    int array_size = id_node->scope;

                    if (array_size > 0 && eval_const_int_expr(index_expr, &index_val)){
                        if (index_val < 0 || index_val >= array_size){
                            printf("error: line %d: Statically sized array indexed with constant, out-of-bounds expression.\n", node->lineno);
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < node->numChildren; i++){
        check_array_indexing(getChild(node, i));
    }
}

// Helpers
int get_expr_type(tree *node){
    if (node == NULL) return -1;

    switch (node->nodeKind){
        case EXPRESSION:
            if (node->numChildren == 1){
                return get_expr_type(getChild(node, 0));
            }
            if (node->numChildren == 3){
                int left = get_expr_type(getChild(node, 0));
                int right = get_expr_type(getChild(node, 2));

                if (left == -1 || right == -1) return -1;
                if (left == VOID_TYPE || right == VOID_TYPE) return -2;
                if (left != right) return -2;

                return INT_TYPE;
            }
            return -1;

        case ADDEXPR:
        case TERM:
            if (node->numChildren == 1){
                return get_expr_type(getChild(node, 0));
            }
            if (node->numChildren == 3){
                int left = get_expr_type(getChild(node, 0));
                int right = get_expr_type(getChild(node, 2));

                if (left == -1 || right == -1) return -1;
                if (left == VOID_TYPE || right == VOID_TYPE) return -2;
                if (left != right) return -2;

                return left;
            }
            return -1;

        case FACTOR:
            if (node->numChildren == 1){
                return get_expr_type(getChild(node, 0));
            }
            return -1;

        case VAR:
        {
            tree *id = getChild(node, 0);
            if (id != NULL && id->nodeKind == IDENTIFIER && id->val != -1){
                return id->type;
            }
            return -1;
        }

        case FUNCALLEXPR:
        {
            tree *id = getChild(node, 0);
            if (id != NULL && id->nodeKind == IDENTIFIER && id->val != -1){
                return id->type;
            }
            return -1;
        }

        case INTEGER:
            return INT_TYPE;

        case CHAR_NODE:
            return CHAR_TYPE;

        case STRING_NODE:
            return -2;

        default:
            return -1;
    }
}

int count_arg_nodes(tree *arglist){
    if (arglist == NULL) return 0;
    if (arglist->nodeKind != ARGLIST) return 0;

    if (arglist->numChildren == 1){
        return 1;
    }
    if (arglist->numChildren == 2){
        return count_arg_nodes(getChild(arglist, 0)) + 1;
    }
    return 0;
}

static void collect_arg_exprs(tree *arglist, tree **args, int *count){
    if (arglist == NULL) return;

    if (arglist->nodeKind != ARGLIST) return;

    if (arglist->numChildren == 1){
        args[*count] = getChild(arglist, 0);
        (*count)++;
        return;
    }

    if (arglist->numChildren == 2){
        collect_arg_exprs(getChild(arglist, 0), args, count);
        args[*count] = getChild(arglist, 1);
        (*count)++;
    }
}

int check_arg_list_types(tree *arglist, param *expected){
    if (arglist == NULL && expected == NULL) return 1;
    if (arglist == NULL || expected == NULL) return 0;

    tree *args[128];
    int arg_count = 0;
    collect_arg_exprs(arglist, args, &arg_count);

    param *p = expected;
    int i = 0;

    while (p != NULL && i < arg_count){
        int actual_type = get_expr_type(args[i]);

        if (actual_type == -1){
            return 0;
        }

        if (actual_type != p->data_type){
            return 0;
        }

        p = p->next;
        i++;
    }

    return (p == NULL && i == arg_count);
}

void check_function_calls(tree *node){
    if (node == NULL) return;

    if (node->nodeKind == FUNCALLEXPR && node->numChildren >= 1){
        tree *id_node = getChild(node, 0);

        if (id_node->nodeKind == IDENTIFIER && id_node->val != -1){
            symEntry *entry = ST_lookup_from_root(id_node->name, get_root_scope());

            if (entry != NULL && entry->symbol_type == FUNCTION){
                tree *arglist = (node->numChildren == 2) ? getChild(node, 1) : NULL;
                int actual_count = count_arg_nodes(arglist);
                int expected_count = entry->size;

                if (actual_count < expected_count){
                    printf("error: line %d: Too few arguments provided in function call.\n", node->lineno);
                }
                else if (actual_count > expected_count){
                    printf("error: line %d: Too many arguments provided in function call.\n", node->lineno);
                }
                else if (!check_arg_list_types(arglist, entry->params)){
                    printf("error: line %d: Argument type mismatch in function call.\n", node->lineno);
                }
            }
        }
    }

    for (int i = 0; i < node->numChildren; i++){
        check_function_calls(getChild(node, i));
    }
}

// Main semantic analysis function
void semantic_analysis(tree *ast){
    if (ast == NULL)
        return;

    check_undeclared_vars_rec(ast, 0);
    check_type_mismatch(ast);
    check_array_indexing(ast);
    check_function_calls(ast);
}