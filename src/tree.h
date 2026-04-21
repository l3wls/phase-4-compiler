#ifndef TREE_H
#define TREE_H

#define MAXCHILDREN 100

// Node kind enumeration
enum nodeKind
{
      PROGRAM,
      DECLLIST,
      DECL,
      VARDECL,
      TYPESPEC,
      FUNDECL,
      FORMALDECLLIST,
      FORMALDECL,
      FUNBODY,
      LOCALDECLLIST,
      STATEMENTLIST,
      STATEMENT,
      COMPOUNDSTMT,
      ASSIGNSTMT,
      CONDSTMT,
      LOOPSTMT,
      RETURNSTMT,
      EXPRESSION,
      RELOP,
      ADDEXPR,
      ADDOP,
      TERM,
      MULOP,
      FACTOR,
      FUNCALLEXPR,
      ARGLIST,
      INTEGER,
      IDENTIFIER,
      VAR,
      ARRAYDECL,
      CHAR_NODE,
      FUNCTYPENAME,
      STRING_NODE
};

// Relational operator kinds
enum relopKind
{
      LTE_OP,
      LT_OP,
      GT_OP,
      GTE_OP,
      EQ_OP,
      NEQ_OP
};

typedef struct treenode tree;

/* tree node */
struct treenode
{
      int nodeKind;
      int numChildren;
      int val;
      int scope;    // Scope index
      int type;     // Data type
      int sym_type; // SCALAR vs ARRAY
      int lineno;   // Line number from parser
      char *name;   // For identifiers/strings
      tree *parent;
      tree *children[MAXCHILDREN];
};

extern tree *ast; /* pointer to AST root */

/* builds sub tree with zero children  */
tree *maketree(int kind);

/* builds sub tree with leaf node */
tree *maketreeWithVal(int kind, int val);

void addChild(tree *parent, tree *child);

void printAst(tree *root, int nestLevel);

/* Adds all children of sublist to list */
void flattenList(tree *list, tree *subList);

/* tree manipulation macros */
#define nextAvailChild(node) node->children[node->numChildren]
#define getChild(node, index) node->children[index]

#endif