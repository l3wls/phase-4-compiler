/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "../src/parser.y"

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


#line 94 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    STRCONST = 259,                /* STRCONST  */
    INTCONST = 260,                /* INTCONST  */
    CHARCONST = 261,               /* CHARCONST  */
    KWD_IF = 262,                  /* KWD_IF  */
    KWD_ELSE = 263,                /* KWD_ELSE  */
    KWD_WHILE = 264,               /* KWD_WHILE  */
    KWD_FOR = 265,                 /* KWD_FOR  */
    KWD_INT = 266,                 /* KWD_INT  */
    KWD_CHAR = 267,                /* KWD_CHAR  */
    KWD_RETURN = 268,              /* KWD_RETURN  */
    KWD_VOID = 269,                /* KWD_VOID  */
    OPER_ADD = 270,                /* OPER_ADD  */
    OPER_SUB = 271,                /* OPER_SUB  */
    OPER_MUL = 272,                /* OPER_MUL  */
    OPER_DIV = 273,                /* OPER_DIV  */
    OPER_MOD = 274,                /* OPER_MOD  */
    OPER_LT = 275,                 /* OPER_LT  */
    OPER_GT = 276,                 /* OPER_GT  */
    OPER_LTE = 277,                /* OPER_LTE  */
    OPER_GTE = 278,                /* OPER_GTE  */
    OPER_EQ = 279,                 /* OPER_EQ  */
    OPER_NEQ = 280,                /* OPER_NEQ  */
    OPER_ASGN = 281,               /* OPER_ASGN  */
    OPER_AT = 282,                 /* OPER_AT  */
    OPER_INC = 283,                /* OPER_INC  */
    OPER_DEC = 284,                /* OPER_DEC  */
    OPER_AND = 285,                /* OPER_AND  */
    OPER_OR = 286,                 /* OPER_OR  */
    OPER_NOT = 287,                /* OPER_NOT  */
    LSQ_BRKT = 288,                /* LSQ_BRKT  */
    RSQ_BRKT = 289,                /* RSQ_BRKT  */
    LCRLY_BRKT = 290,              /* LCRLY_BRKT  */
    RCRLY_BRKT = 291,              /* RCRLY_BRKT  */
    LPAREN = 292,                  /* LPAREN  */
    RPAREN = 293,                  /* RPAREN  */
    COMMA = 294,                   /* COMMA  */
    SEMICLN = 295,                 /* SEMICLN  */
    ERROR = 296,                   /* ERROR  */
    LOWER_THAN_ELSE = 297          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define STRCONST 259
#define INTCONST 260
#define CHARCONST 261
#define KWD_IF 262
#define KWD_ELSE 263
#define KWD_WHILE 264
#define KWD_FOR 265
#define KWD_INT 266
#define KWD_CHAR 267
#define KWD_RETURN 268
#define KWD_VOID 269
#define OPER_ADD 270
#define OPER_SUB 271
#define OPER_MUL 272
#define OPER_DIV 273
#define OPER_MOD 274
#define OPER_LT 275
#define OPER_GT 276
#define OPER_LTE 277
#define OPER_GTE 278
#define OPER_EQ 279
#define OPER_NEQ 280
#define OPER_ASGN 281
#define OPER_AT 282
#define OPER_INC 283
#define OPER_DEC 284
#define OPER_AND 285
#define OPER_OR 286
#define OPER_NOT 287
#define LSQ_BRKT 288
#define RSQ_BRKT 289
#define LCRLY_BRKT 290
#define RCRLY_BRKT 291
#define LPAREN 292
#define RPAREN 293
#define COMMA 294
#define SEMICLN 295
#define ERROR 296
#define LOWER_THAN_ELSE 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "../src/parser.y"

    int value;
    struct treenode *node;
    char *strval;

#line 237 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_STRCONST = 4,                   /* STRCONST  */
  YYSYMBOL_INTCONST = 5,                   /* INTCONST  */
  YYSYMBOL_CHARCONST = 6,                  /* CHARCONST  */
  YYSYMBOL_KWD_IF = 7,                     /* KWD_IF  */
  YYSYMBOL_KWD_ELSE = 8,                   /* KWD_ELSE  */
  YYSYMBOL_KWD_WHILE = 9,                  /* KWD_WHILE  */
  YYSYMBOL_KWD_FOR = 10,                   /* KWD_FOR  */
  YYSYMBOL_KWD_INT = 11,                   /* KWD_INT  */
  YYSYMBOL_KWD_CHAR = 12,                  /* KWD_CHAR  */
  YYSYMBOL_KWD_RETURN = 13,                /* KWD_RETURN  */
  YYSYMBOL_KWD_VOID = 14,                  /* KWD_VOID  */
  YYSYMBOL_OPER_ADD = 15,                  /* OPER_ADD  */
  YYSYMBOL_OPER_SUB = 16,                  /* OPER_SUB  */
  YYSYMBOL_OPER_MUL = 17,                  /* OPER_MUL  */
  YYSYMBOL_OPER_DIV = 18,                  /* OPER_DIV  */
  YYSYMBOL_OPER_MOD = 19,                  /* OPER_MOD  */
  YYSYMBOL_OPER_LT = 20,                   /* OPER_LT  */
  YYSYMBOL_OPER_GT = 21,                   /* OPER_GT  */
  YYSYMBOL_OPER_LTE = 22,                  /* OPER_LTE  */
  YYSYMBOL_OPER_GTE = 23,                  /* OPER_GTE  */
  YYSYMBOL_OPER_EQ = 24,                   /* OPER_EQ  */
  YYSYMBOL_OPER_NEQ = 25,                  /* OPER_NEQ  */
  YYSYMBOL_OPER_ASGN = 26,                 /* OPER_ASGN  */
  YYSYMBOL_OPER_AT = 27,                   /* OPER_AT  */
  YYSYMBOL_OPER_INC = 28,                  /* OPER_INC  */
  YYSYMBOL_OPER_DEC = 29,                  /* OPER_DEC  */
  YYSYMBOL_OPER_AND = 30,                  /* OPER_AND  */
  YYSYMBOL_OPER_OR = 31,                   /* OPER_OR  */
  YYSYMBOL_OPER_NOT = 32,                  /* OPER_NOT  */
  YYSYMBOL_LSQ_BRKT = 33,                  /* LSQ_BRKT  */
  YYSYMBOL_RSQ_BRKT = 34,                  /* RSQ_BRKT  */
  YYSYMBOL_LCRLY_BRKT = 35,                /* LCRLY_BRKT  */
  YYSYMBOL_RCRLY_BRKT = 36,                /* RCRLY_BRKT  */
  YYSYMBOL_LPAREN = 37,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 38,                    /* RPAREN  */
  YYSYMBOL_COMMA = 39,                     /* COMMA  */
  YYSYMBOL_SEMICLN = 40,                   /* SEMICLN  */
  YYSYMBOL_ERROR = 41,                     /* ERROR  */
  YYSYMBOL_LOWER_THAN_ELSE = 42,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_program = 44,                   /* program  */
  YYSYMBOL_declList = 45,                  /* declList  */
  YYSYMBOL_decl = 46,                      /* decl  */
  YYSYMBOL_varDecl = 47,                   /* varDecl  */
  YYSYMBOL_typeSpecifier = 48,             /* typeSpecifier  */
  YYSYMBOL_funDecl = 49,                   /* funDecl  */
  YYSYMBOL_funcTypeName = 50,              /* funcTypeName  */
  YYSYMBOL_formalDeclList = 51,            /* formalDeclList  */
  YYSYMBOL_formalDecl = 52,                /* formalDecl  */
  YYSYMBOL_arrayDecl = 53,                 /* arrayDecl  */
  YYSYMBOL_funBody = 54,                   /* funBody  */
  YYSYMBOL_localDeclList = 55,             /* localDeclList  */
  YYSYMBOL_statementList = 56,             /* statementList  */
  YYSYMBOL_statement = 57,                 /* statement  */
  YYSYMBOL_compoundStmt = 58,              /* compoundStmt  */
  YYSYMBOL_assignStmt = 59,                /* assignStmt  */
  YYSYMBOL_condStmt = 60,                  /* condStmt  */
  YYSYMBOL_loopStmt = 61,                  /* loopStmt  */
  YYSYMBOL_forStmt = 62,                   /* forStmt  */
  YYSYMBOL_returnStmt = 63,                /* returnStmt  */
  YYSYMBOL_var = 64,                       /* var  */
  YYSYMBOL_expression = 65,                /* expression  */
  YYSYMBOL_relop = 66,                     /* relop  */
  YYSYMBOL_addExpr = 67,                   /* addExpr  */
  YYSYMBOL_addop = 68,                     /* addop  */
  YYSYMBOL_term = 69,                      /* term  */
  YYSYMBOL_mulop = 70,                     /* mulop  */
  YYSYMBOL_factor = 71,                    /* factor  */
  YYSYMBOL_funcCallExpr = 72,              /* funcCallExpr  */
  YYSYMBOL_argList = 73                    /* argList  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   192

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  126

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    76,    76,    85,    91,   100,   106,   114,   127,   154,
     158,   162,   168,   186,   205,   230,   236,   245,   260,   279,
     285,   295,   298,   308,   311,   320,   326,   332,   338,   344,
     350,   358,   366,   373,   381,   388,   398,   407,   422,   426,
     434,   452,   473,   479,   489,   490,   491,   492,   493,   494,
     497,   503,   513,   514,   517,   523,   533,   534,   537,   543,
     549,   555,   562,   569,   579,   598,   618,   624
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "STRCONST",
  "INTCONST", "CHARCONST", "KWD_IF", "KWD_ELSE", "KWD_WHILE", "KWD_FOR",
  "KWD_INT", "KWD_CHAR", "KWD_RETURN", "KWD_VOID", "OPER_ADD", "OPER_SUB",
  "OPER_MUL", "OPER_DIV", "OPER_MOD", "OPER_LT", "OPER_GT", "OPER_LTE",
  "OPER_GTE", "OPER_EQ", "OPER_NEQ", "OPER_ASGN", "OPER_AT", "OPER_INC",
  "OPER_DEC", "OPER_AND", "OPER_OR", "OPER_NOT", "LSQ_BRKT", "RSQ_BRKT",
  "LCRLY_BRKT", "RCRLY_BRKT", "LPAREN", "RPAREN", "COMMA", "SEMICLN",
  "ERROR", "LOWER_THAN_ELSE", "$accept", "program", "declList", "decl",
  "varDecl", "typeSpecifier", "funDecl", "funcTypeName", "formalDeclList",
  "formalDecl", "arrayDecl", "funBody", "localDeclList", "statementList",
  "statement", "compoundStmt", "assignStmt", "condStmt", "loopStmt",
  "forStmt", "returnStmt", "var", "expression", "relop", "addExpr",
  "addop", "term", "mulop", "factor", "funcCallExpr", "argList", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-63)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      62,   -63,   -63,   -63,     4,    62,   -63,   -63,    -1,   -63,
     -22,   -63,   -63,     1,    49,    25,   -63,    11,    36,    20,
      23,    32,    62,   -63,    39,    11,    62,    73,    62,    90,
      22,    50,   -63,   -63,   -63,   -63,   -63,     1,     5,   -63,
     -63,   -63,    77,    79,    80,     3,    22,    44,    82,    22,
     -63,   -63,   -63,   -63,   -63,   -63,    93,    31,    67,    71,
     -63,   -63,   -63,    44,     7,    44,    44,   117,   -63,   -63,
      75,    86,   114,   -63,   -63,    44,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,    44,   -63,   -63,    44,   -63,   -63,    44,
       2,   -63,   167,    53,   120,   139,    91,    97,   -63,   -63,
     -63,    81,    67,    71,   -63,   -63,   -63,    44,    22,    22,
      44,   -63,   167,   118,   -63,    87,    22,    44,   -63,   108,
     117,    99,    44,   145,    22,   -63
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,    11,     0,     2,     3,     5,     0,     6,
       0,     1,     4,    14,     0,     0,     7,     0,     0,     0,
      15,     0,    21,    13,    17,     0,     0,     0,    21,     0,
      23,     0,    18,    12,    16,     8,    22,     0,    40,    63,
      61,    62,     0,     0,     0,     0,    23,     0,     0,    23,
      26,    25,    27,    28,    29,    30,    59,     0,    42,    50,
      54,    60,    19,     0,     0,     0,     0,     0,    38,    59,
       0,     0,     0,    20,    24,     0,    45,    46,    44,    47,
      48,    49,    33,     0,    52,    53,     0,    56,    57,     0,
       0,    65,    66,     0,     0,     0,    40,     0,    39,    31,
      58,     0,    43,    51,    55,    41,    64,     0,     0,     0,
       0,    32,    67,    34,    36,     0,     0,     0,    35,     0,
       0,     0,     0,     0,     0,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -63,   -63,   -63,   141,    -8,   158,   -63,   -63,   121,   -63,
     -63,   124,   122,    18,   -39,   -63,   -63,   -63,   -63,   -63,
     -63,   -30,   -42,   -63,   -62,   -63,    65,   -63,    64,   -63,
     -63
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,     9,    10,    19,    20,
      32,    23,    30,    48,    49,    50,    51,    52,    53,    54,
      55,    69,    57,    83,    58,    86,    59,    89,    60,    61,
      93
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      56,    90,    13,    70,    11,    72,    38,    39,    40,    41,
      38,    39,    40,    41,    28,    14,    56,    84,    85,    56,
      28,   102,    92,    94,    95,    38,    39,    40,    41,    42,
      21,    43,    44,   101,    15,    45,   105,    97,    63,    24,
      47,    16,    64,    68,    47,    91,    22,    38,    39,    40,
      41,    76,    77,    78,    79,    80,    81,    46,    25,    47,
       1,     2,    26,     3,    71,   112,    27,    74,   115,   113,
     114,    82,    31,     1,     2,   119,     3,   118,    56,    56,
     123,    47,    84,    85,    62,   125,    56,    17,    87,    88,
     121,   106,   107,    37,    56,    76,    77,    78,    79,    80,
      81,    76,    77,    78,    79,    80,    81,    76,    77,    78,
      79,    80,    81,    35,    65,    98,    66,    67,    73,    75,
      96,   111,    99,   110,    63,   122,   116,   117,    76,    77,
      78,    79,    80,    81,    76,    77,    78,    79,    80,    81,
      76,    77,    78,    79,    80,    81,    12,    34,   120,    33,
      36,   103,   100,   104,     0,     0,     0,     0,   108,    76,
      77,    78,    79,    80,    81,    76,    77,    78,    79,    80,
      81,     0,    18,     0,     0,     0,     0,   109,     0,     0,
      29,     0,     0,   124,    18,     0,    29,    76,    77,    78,
      79,    80,    81
};

static const yytype_int8 yycheck[] =
{
      30,    63,     3,    45,     0,    47,     3,     4,     5,     6,
       3,     4,     5,     6,    22,    37,    46,    15,    16,    49,
      28,    83,    64,    65,    66,     3,     4,     5,     6,     7,
       5,     9,    10,    75,    33,    13,    34,    67,    33,     3,
      37,    40,    37,    40,    37,    38,    35,     3,     4,     5,
       6,    20,    21,    22,    23,    24,    25,    35,    38,    37,
      11,    12,    39,    14,    46,   107,    34,    49,   110,   108,
     109,    40,    33,    11,    12,   117,    14,   116,   108,   109,
     122,    37,    15,    16,    34,   124,   116,    38,    17,    18,
     120,    38,    39,     3,   124,    20,    21,    22,    23,    24,
      25,    20,    21,    22,    23,    24,    25,    20,    21,    22,
      23,    24,    25,    40,    37,    40,    37,    37,    36,    26,
       3,    40,    36,    26,    33,    26,     8,    40,    20,    21,
      22,    23,    24,    25,    20,    21,    22,    23,    24,    25,
      20,    21,    22,    23,    24,    25,     5,    26,    40,    25,
      28,    86,    38,    89,    -1,    -1,    -1,    -1,    38,    20,
      21,    22,    23,    24,    25,    20,    21,    22,    23,    24,
      25,    -1,    14,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      22,    -1,    -1,    38,    26,    -1,    28,    20,    21,    22,
      23,    24,    25
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    12,    14,    44,    45,    46,    47,    48,    49,
      50,     0,    46,     3,    37,    33,    40,    38,    48,    51,
      52,     5,    35,    54,     3,    38,    39,    34,    47,    48,
      55,    33,    53,    54,    51,    40,    55,     3,     3,     4,
       5,     6,     7,     9,    10,    13,    35,    37,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    67,    69,
      71,    72,    34,    33,    37,    37,    37,    37,    40,    64,
      65,    56,    65,    36,    56,    26,    20,    21,    22,    23,
      24,    25,    40,    66,    15,    16,    68,    17,    18,    70,
      67,    38,    65,    73,    65,    65,     3,    64,    40,    36,
      38,    65,    67,    69,    71,    34,    38,    39,    38,    38,
      26,    40,    65,    57,    57,    65,     8,    40,    57,    65,
      40,    64,    26,    65,    38,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    47,    47,    48,
      48,    48,    49,    49,    50,    51,    51,    52,    52,    53,
      54,    55,    55,    56,    56,    57,    57,    57,    57,    57,
      57,    58,    59,    59,    60,    60,    61,    62,    63,    63,
      64,    64,    65,    65,    66,    66,    66,    66,    66,    66,
      67,    67,    68,    68,    69,    69,    70,    70,    71,    71,
      71,    71,    71,    71,    72,    72,    73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     6,     1,
       1,     1,     5,     4,     2,     1,     3,     2,     3,     2,
       4,     0,     2,     0,     2,     1,     1,     1,     1,     1,
       1,     3,     4,     2,     5,     7,     5,    13,     2,     3,
       1,     4,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     3,     1,
       1,     1,     1,     1,     4,     3,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: declList  */
#line 77 "../src/parser.y"
    {
        tree *progNode = maketree(PROGRAM);
        addChild(progNode, (yyvsp[0].node));
        ast = progNode;
        (yyval.node) = progNode;
    }
#line 1393 "y.tab.c"
    break;

  case 3: /* declList: decl  */
#line 86 "../src/parser.y"
    {
        tree* declListNode = maketree(DECLLIST);
        addChild(declListNode, (yyvsp[0].node));
        (yyval.node) = declListNode;
    }
#line 1403 "y.tab.c"
    break;

  case 4: /* declList: declList decl  */
#line 92 "../src/parser.y"
    {
        tree* declListNode = maketree(DECLLIST);
        addChild(declListNode, (yyvsp[-1].node));
        addChild(declListNode, (yyvsp[0].node));
        (yyval.node) = declListNode;
    }
#line 1414 "y.tab.c"
    break;

  case 5: /* decl: varDecl  */
#line 101 "../src/parser.y"
    {
        tree* declNode = maketree(DECL);
        addChild(declNode, (yyvsp[0].node));
        (yyval.node) = declNode;
    }
#line 1424 "y.tab.c"
    break;

  case 6: /* decl: funDecl  */
#line 107 "../src/parser.y"
    {
        tree* declNode = maketree(DECL);
        addChild(declNode, (yyvsp[0].node));
        (yyval.node) = declNode;
    }
#line 1434 "y.tab.c"
    break;

  case 7: /* varDecl: typeSpecifier ID SEMICLN  */
#line 115 "../src/parser.y"
    {
        tree* varDeclNode = maketree(VARDECL);
        addChild(varDeclNode, (yyvsp[-2].node));
        
        tree* idNode = maketree(IDENTIFIER);
        idNode->name = strdup((yyvsp[-1].strval));
        addChild(varDeclNode, idNode);
        
        ST_insert((yyvsp[-1].strval), (yyvsp[-2].node)->val, SCALAR, NULL);
        
        (yyval.node) = varDeclNode;
    }
#line 1451 "y.tab.c"
    break;

  case 8: /* varDecl: typeSpecifier ID LSQ_BRKT INTCONST RSQ_BRKT SEMICLN  */
#line 128 "../src/parser.y"
    {
        tree* varDeclNode = maketree(VARDECL);
        addChild(varDeclNode, (yyvsp[-5].node));

        tree* idNode = maketree(IDENTIFIER);
        idNode->name = strdup((yyvsp[-4].strval));
        addChild(varDeclNode, idNode);

        tree* sizeNode = maketreeWithVal(INTEGER, (yyvsp[-2].value));
        addChild(varDeclNode, sizeNode);

        int array_index = -1;
        ST_insert((yyvsp[-4].strval), (yyvsp[-5].node)->val, ARRAY, &array_index);

        if (array_index != -1 && current_scope->strTable[array_index] != NULL) {
            current_scope->strTable[array_index]->size = (yyvsp[-2].value);
        }

        if ((yyvsp[-2].value) == 0){
            printf("error: line %d: Array variable declared with size of zero.\n", yylineno);
        }

        (yyval.node) = varDeclNode;
    }
#line 1480 "y.tab.c"
    break;

  case 9: /* typeSpecifier: KWD_INT  */
#line 155 "../src/parser.y"
    {
        (yyval.node) = maketreeWithVal(TYPESPEC, INT_TYPE);
    }
#line 1488 "y.tab.c"
    break;

  case 10: /* typeSpecifier: KWD_CHAR  */
#line 159 "../src/parser.y"
    {
        (yyval.node) = maketreeWithVal(TYPESPEC, CHAR_TYPE);
    }
#line 1496 "y.tab.c"
    break;

  case 11: /* typeSpecifier: KWD_VOID  */
#line 163 "../src/parser.y"
    {
        (yyval.node) = maketreeWithVal(TYPESPEC, VOID_TYPE);
    }
#line 1504 "y.tab.c"
    break;

  case 12: /* funDecl: funcTypeName LPAREN formalDeclList RPAREN funBody  */
#line 169 "../src/parser.y"
    {
        tree* funDeclNode = maketree(FUNDECL);
        addChild(funDeclNode, (yyvsp[-4].node));
        addChild(funDeclNode, (yyvsp[-2].node));
        addChild(funDeclNode, (yyvsp[0].node));

        if (current_function_index != -1) {
            connect_params(current_function_index, current_function_param_count);
        }

        up_scope();  // exit function scope
        current_scope_name = NULL;
        current_function_index = -1;
        current_function_param_count = 0;

        (yyval.node) = funDeclNode;
    }
#line 1526 "y.tab.c"
    break;

  case 13: /* funDecl: funcTypeName LPAREN RPAREN funBody  */
#line 187 "../src/parser.y"
    {
        tree* funDeclNode = maketree(FUNDECL);
        addChild(funDeclNode, (yyvsp[-3].node));
        addChild(funDeclNode, (yyvsp[0].node));

        if (current_function_index != -1) {
            connect_params(current_function_index, 0);
        }

        up_scope();  // exit function scope
        current_scope_name = NULL;
        current_function_index = -1;
        current_function_param_count = 0;

        (yyval.node) = funDeclNode;
    }
#line 1547 "y.tab.c"
    break;

  case 14: /* funcTypeName: typeSpecifier ID  */
#line 206 "../src/parser.y"
    {
        tree* funcTypeNameNode = maketree(FUNCTYPENAME);
        addChild(funcTypeNameNode, (yyvsp[-1].node));

        tree* idNode = maketree(IDENTIFIER);
        idNode->name = strdup((yyvsp[0].strval));
        addChild(funcTypeNameNode, idNode);

        int func_index = -1;
        ST_insert((yyvsp[0].strval), (yyvsp[-1].node)->val, FUNCTION, &func_index);

        current_function_index = func_index;
        current_function_param_count = 0;
        current_scope_name = strdup((yyvsp[0].strval));

        working_list_head = NULL;
        working_list_end = NULL;

        new_scope();

        (yyval.node) = funcTypeNameNode;
    }
#line 1574 "y.tab.c"
    break;

  case 15: /* formalDeclList: formalDecl  */
#line 231 "../src/parser.y"
    {
        tree* formalDeclListNode = maketree(FORMALDECLLIST);
        addChild(formalDeclListNode, (yyvsp[0].node));
        (yyval.node) = formalDeclListNode;
    }
#line 1584 "y.tab.c"
    break;

  case 16: /* formalDeclList: formalDecl COMMA formalDeclList  */
#line 237 "../src/parser.y"
    {
        tree* formalDeclListNode = maketree(FORMALDECLLIST);
        addChild(formalDeclListNode, (yyvsp[-2].node));
        addChild(formalDeclListNode, (yyvsp[0].node));
        (yyval.node) = formalDeclListNode;
    }
#line 1595 "y.tab.c"
    break;

  case 17: /* formalDecl: typeSpecifier ID  */
#line 246 "../src/parser.y"
    {
        tree* formalDeclNode = maketree(FORMALDECL);
        addChild(formalDeclNode, (yyvsp[-1].node));

        tree* idNode = maketree(IDENTIFIER);
        idNode->name = strdup((yyvsp[0].strval));
        addChild(formalDeclNode, idNode);

        ST_insert((yyvsp[0].strval), (yyvsp[-1].node)->val, SCALAR, NULL);
        add_param((yyvsp[-1].node)->val, SCALAR);
        current_function_param_count++;

        (yyval.node) = formalDeclNode;
    }
#line 1614 "y.tab.c"
    break;

  case 18: /* formalDecl: typeSpecifier ID arrayDecl  */
#line 261 "../src/parser.y"
    {
        tree* formalDeclNode = maketree(FORMALDECL);
        addChild(formalDeclNode, (yyvsp[-2].node));

        tree* idNode = maketree(IDENTIFIER);
        idNode->name = strdup((yyvsp[-1].strval));
        addChild(formalDeclNode, idNode);

        addChild(formalDeclNode, (yyvsp[0].node));

        ST_insert((yyvsp[-1].strval), (yyvsp[-2].node)->val, ARRAY, NULL);
        add_param((yyvsp[-2].node)->val, ARRAY);
        current_function_param_count++;

        (yyval.node) = formalDeclNode;
    }
#line 1635 "y.tab.c"
    break;

  case 19: /* arrayDecl: LSQ_BRKT RSQ_BRKT  */
#line 280 "../src/parser.y"
    {
        (yyval.node) = maketree(ARRAYDECL);
    }
#line 1643 "y.tab.c"
    break;

  case 20: /* funBody: LCRLY_BRKT localDeclList statementList RCRLY_BRKT  */
#line 286 "../src/parser.y"
    {
        tree* funBodyNode = maketree(FUNBODY);
        if ((yyvsp[-2].node) != NULL) addChild(funBodyNode, (yyvsp[-2].node));
        if ((yyvsp[-1].node) != NULL) addChild(funBodyNode, (yyvsp[-1].node));
        (yyval.node) = funBodyNode;
    }
#line 1654 "y.tab.c"
    break;

  case 21: /* localDeclList: %empty  */
#line 295 "../src/parser.y"
    {
        (yyval.node) = NULL;
    }
#line 1662 "y.tab.c"
    break;

  case 22: /* localDeclList: varDecl localDeclList  */
#line 299 "../src/parser.y"
    {
        tree* localDeclListNode = maketree(LOCALDECLLIST);
        addChild(localDeclListNode, (yyvsp[-1].node));
        if ((yyvsp[0].node) != NULL) addChild(localDeclListNode, (yyvsp[0].node));
        (yyval.node) = localDeclListNode;
    }
#line 1673 "y.tab.c"
    break;

  case 23: /* statementList: %empty  */
#line 308 "../src/parser.y"
    {
        (yyval.node) = NULL;
    }
#line 1681 "y.tab.c"
    break;

  case 24: /* statementList: statement statementList  */
#line 312 "../src/parser.y"
    {
        tree* stmtListNode = maketree(STATEMENTLIST);
        addChild(stmtListNode, (yyvsp[-1].node));
        if ((yyvsp[0].node) != NULL) addChild(stmtListNode, (yyvsp[0].node));
        (yyval.node) = stmtListNode;
    }
#line 1692 "y.tab.c"
    break;

  case 25: /* statement: assignStmt  */
#line 321 "../src/parser.y"
    {
        tree* stmtNode = maketree(STATEMENT);
        addChild(stmtNode, (yyvsp[0].node));
        (yyval.node) = stmtNode;
    }
#line 1702 "y.tab.c"
    break;

  case 26: /* statement: compoundStmt  */
#line 327 "../src/parser.y"
    {
        tree* stmtNode = maketree(STATEMENT);
        addChild(stmtNode, (yyvsp[0].node));
        (yyval.node) = stmtNode;
    }
#line 1712 "y.tab.c"
    break;

  case 27: /* statement: condStmt  */
#line 333 "../src/parser.y"
    {
        tree* stmtNode = maketree(STATEMENT);
        addChild(stmtNode, (yyvsp[0].node));
        (yyval.node) = stmtNode;
    }
#line 1722 "y.tab.c"
    break;

  case 28: /* statement: loopStmt  */
#line 339 "../src/parser.y"
    {
        tree* stmtNode = maketree(STATEMENT);
        addChild(stmtNode, (yyvsp[0].node));
        (yyval.node) = stmtNode;
    }
#line 1732 "y.tab.c"
    break;

  case 29: /* statement: forStmt  */
#line 345 "../src/parser.y"
    {
        tree* stmtNode = maketree(STATEMENT);
        addChild(stmtNode, (yyvsp[0].node));
        (yyval.node) = stmtNode;
    }
#line 1742 "y.tab.c"
    break;

  case 30: /* statement: returnStmt  */
#line 351 "../src/parser.y"
    {
        tree* stmtNode = maketree(STATEMENT);
        addChild(stmtNode, (yyvsp[0].node));
        (yyval.node) = stmtNode;
    }
#line 1752 "y.tab.c"
    break;

  case 31: /* compoundStmt: LCRLY_BRKT statementList RCRLY_BRKT  */
#line 359 "../src/parser.y"
    {
        tree* compStmtNode = maketree(COMPOUNDSTMT);
        if ((yyvsp[-1].node) != NULL) addChild(compStmtNode, (yyvsp[-1].node));
        (yyval.node) = compStmtNode;
    }
#line 1762 "y.tab.c"
    break;

  case 32: /* assignStmt: var OPER_ASGN expression SEMICLN  */
#line 367 "../src/parser.y"
    {
        tree* assignNode = maketree(ASSIGNSTMT);
        addChild(assignNode, (yyvsp[-3].node));
        addChild(assignNode, (yyvsp[-1].node));
        (yyval.node) = assignNode;
    }
#line 1773 "y.tab.c"
    break;

  case 33: /* assignStmt: expression SEMICLN  */
#line 374 "../src/parser.y"
    {
        tree* assignNode = maketree(ASSIGNSTMT);
        addChild(assignNode, (yyvsp[-1].node));
        (yyval.node) = assignNode;
    }
#line 1783 "y.tab.c"
    break;

  case 34: /* condStmt: KWD_IF LPAREN expression RPAREN statement  */
#line 382 "../src/parser.y"
    {
        tree* condNode = maketree(CONDSTMT);
        addChild(condNode, (yyvsp[-2].node));
        addChild(condNode, (yyvsp[0].node));
        (yyval.node) = condNode;
    }
#line 1794 "y.tab.c"
    break;

  case 35: /* condStmt: KWD_IF LPAREN expression RPAREN statement KWD_ELSE statement  */
#line 389 "../src/parser.y"
    {
        tree* condNode = maketree(CONDSTMT);
        addChild(condNode, (yyvsp[-4].node));
        addChild(condNode, (yyvsp[-2].node));
        addChild(condNode, (yyvsp[0].node));
        (yyval.node) = condNode;
    }
#line 1806 "y.tab.c"
    break;

  case 36: /* loopStmt: KWD_WHILE LPAREN expression RPAREN statement  */
#line 399 "../src/parser.y"
    {
        tree* loopNode = maketree(LOOPSTMT);
        addChild(loopNode, (yyvsp[-2].node));
        addChild(loopNode, (yyvsp[0].node));
        (yyval.node) = loopNode;
    }
#line 1817 "y.tab.c"
    break;

  case 37: /* forStmt: KWD_FOR LPAREN var OPER_ASGN expression SEMICLN expression SEMICLN var OPER_ASGN expression RPAREN statement  */
#line 408 "../src/parser.y"
    {
        /* for(init_var = init_expr; condition; update_var = update_expr) body */
        /* children: [0]=init_var [1]=init_expr [2]=condition [3]=update_var [4]=update_expr [5]=body */
        tree* forNode = maketree(FORSTMT);
        addChild(forNode, (yyvsp[-10].node));   /* init var */
        addChild(forNode, (yyvsp[-8].node));   /* init expr */
        addChild(forNode, (yyvsp[-6].node));   /* condition */
        addChild(forNode, (yyvsp[-4].node));   /* update var */
        addChild(forNode, (yyvsp[-2].node));  /* update expr */
        addChild(forNode, (yyvsp[0].node));  /* body */
        (yyval.node) = forNode;
    }
#line 1834 "y.tab.c"
    break;

  case 38: /* returnStmt: KWD_RETURN SEMICLN  */
#line 423 "../src/parser.y"
    {
        (yyval.node) = maketree(RETURNSTMT);
    }
#line 1842 "y.tab.c"
    break;

  case 39: /* returnStmt: KWD_RETURN expression SEMICLN  */
#line 427 "../src/parser.y"
    {
        tree* returnNode = maketree(RETURNSTMT);
        addChild(returnNode, (yyvsp[-1].node));
        (yyval.node) = returnNode;
    }
#line 1852 "y.tab.c"
    break;

  case 40: /* var: ID  */
#line 435 "../src/parser.y"
    {
        tree* varNode = maketree(VAR);
        tree* idNode = maketree(IDENTIFIER);
        idNode->name = strdup((yyvsp[0].strval));

        symEntry* entry = ST_lookup_silent((yyvsp[0].strval));
        if (entry == NULL) {
            idNode->val = -1;
        } else {
            idNode->type = entry->data_type;
            idNode->sym_type = entry->symbol_type;
            idNode->scope = entry->size;
        }

        addChild(varNode, idNode);
        (yyval.node) = varNode;
    }
#line 1874 "y.tab.c"
    break;

  case 41: /* var: ID LSQ_BRKT addExpr RSQ_BRKT  */
#line 453 "../src/parser.y"
    {
        tree* varNode = maketree(VAR);
        tree* idNode = maketree(IDENTIFIER);
        idNode->name = strdup((yyvsp[-3].strval));

        symEntry* entry = ST_lookup_silent((yyvsp[-3].strval));
        if (entry == NULL) {
            idNode->val = -1;
        } else {
            idNode->type = entry->data_type;
            idNode->sym_type = entry->symbol_type;
            idNode->scope = entry->size;
        }

        addChild(varNode, idNode);
        addChild(varNode, (yyvsp[-1].node));
        (yyval.node) = varNode;
    }
#line 1897 "y.tab.c"
    break;

  case 42: /* expression: addExpr  */
#line 474 "../src/parser.y"
    {
        tree* exprNode = maketree(EXPRESSION);
        addChild(exprNode, (yyvsp[0].node));
        (yyval.node) = exprNode;
    }
#line 1907 "y.tab.c"
    break;

  case 43: /* expression: expression relop addExpr  */
#line 480 "../src/parser.y"
    {
        tree* exprNode = maketree(EXPRESSION);
        addChild(exprNode, (yyvsp[-2].node));
        addChild(exprNode, (yyvsp[-1].node));
        addChild(exprNode, (yyvsp[0].node));
        (yyval.node) = exprNode;
    }
#line 1919 "y.tab.c"
    break;

  case 44: /* relop: OPER_LTE  */
#line 489 "../src/parser.y"
                  { (yyval.node) = maketreeWithVal(RELOP, LTE_OP); }
#line 1925 "y.tab.c"
    break;

  case 45: /* relop: OPER_LT  */
#line 490 "../src/parser.y"
                  { (yyval.node) = maketreeWithVal(RELOP, LT_OP); }
#line 1931 "y.tab.c"
    break;

  case 46: /* relop: OPER_GT  */
#line 491 "../src/parser.y"
                  { (yyval.node) = maketreeWithVal(RELOP, GT_OP); }
#line 1937 "y.tab.c"
    break;

  case 47: /* relop: OPER_GTE  */
#line 492 "../src/parser.y"
                  { (yyval.node) = maketreeWithVal(RELOP, GTE_OP); }
#line 1943 "y.tab.c"
    break;

  case 48: /* relop: OPER_EQ  */
#line 493 "../src/parser.y"
                  { (yyval.node) = maketreeWithVal(RELOP, EQ_OP); }
#line 1949 "y.tab.c"
    break;

  case 49: /* relop: OPER_NEQ  */
#line 494 "../src/parser.y"
                  { (yyval.node) = maketreeWithVal(RELOP, NEQ_OP); }
#line 1955 "y.tab.c"
    break;

  case 50: /* addExpr: term  */
#line 498 "../src/parser.y"
    {
        tree* addExprNode = maketree(ADDEXPR);
        addChild(addExprNode, (yyvsp[0].node));
        (yyval.node) = addExprNode;
    }
#line 1965 "y.tab.c"
    break;

  case 51: /* addExpr: addExpr addop term  */
#line 504 "../src/parser.y"
    {
        tree* addExprNode = maketree(ADDEXPR);
        addChild(addExprNode, (yyvsp[-2].node));
        addChild(addExprNode, (yyvsp[-1].node));
        addChild(addExprNode, (yyvsp[0].node));
        (yyval.node) = addExprNode;
    }
#line 1977 "y.tab.c"
    break;

  case 52: /* addop: OPER_ADD  */
#line 513 "../src/parser.y"
                  { (yyval.node) = maketreeWithVal(ADDOP, 0); }
#line 1983 "y.tab.c"
    break;

  case 53: /* addop: OPER_SUB  */
#line 514 "../src/parser.y"
                  { (yyval.node) = maketreeWithVal(ADDOP, 1); }
#line 1989 "y.tab.c"
    break;

  case 54: /* term: factor  */
#line 518 "../src/parser.y"
    {
        tree* termNode = maketree(TERM);
        addChild(termNode, (yyvsp[0].node));
        (yyval.node) = termNode;
    }
#line 1999 "y.tab.c"
    break;

  case 55: /* term: term mulop factor  */
#line 524 "../src/parser.y"
    {
        tree* termNode = maketree(TERM);
        addChild(termNode, (yyvsp[-2].node));
        addChild(termNode, (yyvsp[-1].node));
        addChild(termNode, (yyvsp[0].node));
        (yyval.node) = termNode;
    }
#line 2011 "y.tab.c"
    break;

  case 56: /* mulop: OPER_MUL  */
#line 533 "../src/parser.y"
                  { (yyval.node) = maketreeWithVal(MULOP, 2); }
#line 2017 "y.tab.c"
    break;

  case 57: /* mulop: OPER_DIV  */
#line 534 "../src/parser.y"
                  { (yyval.node) = maketreeWithVal(MULOP, 3); }
#line 2023 "y.tab.c"
    break;

  case 58: /* factor: LPAREN expression RPAREN  */
#line 538 "../src/parser.y"
    {
        tree* factorNode = maketree(FACTOR);
        addChild(factorNode, (yyvsp[-1].node));
        (yyval.node) = factorNode;
    }
#line 2033 "y.tab.c"
    break;

  case 59: /* factor: var  */
#line 544 "../src/parser.y"
    {
        tree* factorNode = maketree(FACTOR);
        addChild(factorNode, (yyvsp[0].node));
        (yyval.node) = factorNode;
    }
#line 2043 "y.tab.c"
    break;

  case 60: /* factor: funcCallExpr  */
#line 550 "../src/parser.y"
    {
        tree* factorNode = maketree(FACTOR);
        addChild(factorNode, (yyvsp[0].node));
        (yyval.node) = factorNode;
    }
#line 2053 "y.tab.c"
    break;

  case 61: /* factor: INTCONST  */
#line 556 "../src/parser.y"
    {
        tree* factorNode = maketree(FACTOR);
        tree* intNode = maketreeWithVal(INTEGER, (yyvsp[0].value));
        addChild(factorNode, intNode);
        (yyval.node) = factorNode;
    }
#line 2064 "y.tab.c"
    break;

  case 62: /* factor: CHARCONST  */
#line 563 "../src/parser.y"
    {
        tree* factorNode = maketree(FACTOR);
        tree* charNode = maketreeWithVal(CHAR_NODE, (yyvsp[0].value));
        addChild(factorNode, charNode);
        (yyval.node) = factorNode;
    }
#line 2075 "y.tab.c"
    break;

  case 63: /* factor: STRCONST  */
#line 570 "../src/parser.y"
    {
        tree* factorNode = maketree(FACTOR);
        tree* strNode = maketree(STRING_NODE);
        strNode->name = strdup((yyvsp[0].strval));
        addChild(factorNode, strNode);
        (yyval.node) = factorNode;
    }
#line 2087 "y.tab.c"
    break;

  case 64: /* funcCallExpr: ID LPAREN argList RPAREN  */
#line 580 "../src/parser.y"
    {
        tree* funcCallNode = maketree(FUNCALLEXPR);
        tree* idNode = maketree(IDENTIFIER);
        idNode->name = strdup((yyvsp[-3].strval));

        symEntry* entry = ST_lookup_silent((yyvsp[-3].strval));
        if (entry == NULL || entry->symbol_type != FUNCTION) {
            printf("error: line %d: Undefined function\n", yylineno);
            idNode->val = -1;
        } else {
            idNode->type = entry->data_type;
            idNode->sym_type = entry->symbol_type;
        }

        addChild(funcCallNode, idNode);
        addChild(funcCallNode, (yyvsp[-1].node));
        (yyval.node) = funcCallNode;
    }
#line 2110 "y.tab.c"
    break;

  case 65: /* funcCallExpr: ID LPAREN RPAREN  */
#line 599 "../src/parser.y"
    {
        tree* funcCallNode = maketree(FUNCALLEXPR);
        tree* idNode = maketree(IDENTIFIER);
        idNode->name = strdup((yyvsp[-2].strval));

        symEntry* entry = ST_lookup_silent((yyvsp[-2].strval));
        if (entry == NULL || entry->symbol_type != FUNCTION) {
            printf("error: line %d: Undefined function\n", yylineno);
            idNode->val = -1;
        } else {
            idNode->type = entry->data_type;
            idNode->sym_type = entry->symbol_type;
        }

        addChild(funcCallNode, idNode);
        (yyval.node) = funcCallNode;
    }
#line 2132 "y.tab.c"
    break;

  case 66: /* argList: expression  */
#line 619 "../src/parser.y"
    {
        tree* argListNode = maketree(ARGLIST);
        addChild(argListNode, (yyvsp[0].node));
        (yyval.node) = argListNode;
    }
#line 2142 "y.tab.c"
    break;

  case 67: /* argList: argList COMMA expression  */
#line 625 "../src/parser.y"
    {
        tree* argListNode = maketree(ARGLIST);
        addChild(argListNode, (yyvsp[-2].node));
        addChild(argListNode, (yyvsp[0].node));
        (yyval.node) = argListNode;
    }
#line 2153 "y.tab.c"
    break;


#line 2157 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 633 "../src/parser.y"


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
