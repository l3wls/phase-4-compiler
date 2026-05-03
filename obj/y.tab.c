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
    KWD_INT = 265,                 /* KWD_INT  */
    KWD_CHAR = 266,                /* KWD_CHAR  */
    KWD_RETURN = 267,              /* KWD_RETURN  */
    KWD_VOID = 268,                /* KWD_VOID  */
    OPER_ADD = 269,                /* OPER_ADD  */
    OPER_SUB = 270,                /* OPER_SUB  */
    OPER_MUL = 271,                /* OPER_MUL  */
    OPER_DIV = 272,                /* OPER_DIV  */
    OPER_MOD = 273,                /* OPER_MOD  */
    OPER_LT = 274,                 /* OPER_LT  */
    OPER_GT = 275,                 /* OPER_GT  */
    OPER_LTE = 276,                /* OPER_LTE  */
    OPER_GTE = 277,                /* OPER_GTE  */
    OPER_EQ = 278,                 /* OPER_EQ  */
    OPER_NEQ = 279,                /* OPER_NEQ  */
    OPER_ASGN = 280,               /* OPER_ASGN  */
    OPER_AT = 281,                 /* OPER_AT  */
    OPER_INC = 282,                /* OPER_INC  */
    OPER_DEC = 283,                /* OPER_DEC  */
    OPER_AND = 284,                /* OPER_AND  */
    OPER_OR = 285,                 /* OPER_OR  */
    OPER_NOT = 286,                /* OPER_NOT  */
    LSQ_BRKT = 287,                /* LSQ_BRKT  */
    RSQ_BRKT = 288,                /* RSQ_BRKT  */
    LCRLY_BRKT = 289,              /* LCRLY_BRKT  */
    RCRLY_BRKT = 290,              /* RCRLY_BRKT  */
    LPAREN = 291,                  /* LPAREN  */
    RPAREN = 292,                  /* RPAREN  */
    COMMA = 293,                   /* COMMA  */
    SEMICLN = 294,                 /* SEMICLN  */
    ERROR = 295,                   /* ERROR  */
    LOWER_THAN_ELSE = 296          /* LOWER_THAN_ELSE  */
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
#define KWD_INT 265
#define KWD_CHAR 266
#define KWD_RETURN 267
#define KWD_VOID 268
#define OPER_ADD 269
#define OPER_SUB 270
#define OPER_MUL 271
#define OPER_DIV 272
#define OPER_MOD 273
#define OPER_LT 274
#define OPER_GT 275
#define OPER_LTE 276
#define OPER_GTE 277
#define OPER_EQ 278
#define OPER_NEQ 279
#define OPER_ASGN 280
#define OPER_AT 281
#define OPER_INC 282
#define OPER_DEC 283
#define OPER_AND 284
#define OPER_OR 285
#define OPER_NOT 286
#define LSQ_BRKT 287
#define RSQ_BRKT 288
#define LCRLY_BRKT 289
#define RCRLY_BRKT 290
#define LPAREN 291
#define RPAREN 292
#define COMMA 293
#define SEMICLN 294
#define ERROR 295
#define LOWER_THAN_ELSE 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "../src/parser.y"

    int value;
    struct treenode *node;
    char *strval;

#line 235 "y.tab.c"

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
  YYSYMBOL_KWD_INT = 10,                   /* KWD_INT  */
  YYSYMBOL_KWD_CHAR = 11,                  /* KWD_CHAR  */
  YYSYMBOL_KWD_RETURN = 12,                /* KWD_RETURN  */
  YYSYMBOL_KWD_VOID = 13,                  /* KWD_VOID  */
  YYSYMBOL_OPER_ADD = 14,                  /* OPER_ADD  */
  YYSYMBOL_OPER_SUB = 15,                  /* OPER_SUB  */
  YYSYMBOL_OPER_MUL = 16,                  /* OPER_MUL  */
  YYSYMBOL_OPER_DIV = 17,                  /* OPER_DIV  */
  YYSYMBOL_OPER_MOD = 18,                  /* OPER_MOD  */
  YYSYMBOL_OPER_LT = 19,                   /* OPER_LT  */
  YYSYMBOL_OPER_GT = 20,                   /* OPER_GT  */
  YYSYMBOL_OPER_LTE = 21,                  /* OPER_LTE  */
  YYSYMBOL_OPER_GTE = 22,                  /* OPER_GTE  */
  YYSYMBOL_OPER_EQ = 23,                   /* OPER_EQ  */
  YYSYMBOL_OPER_NEQ = 24,                  /* OPER_NEQ  */
  YYSYMBOL_OPER_ASGN = 25,                 /* OPER_ASGN  */
  YYSYMBOL_OPER_AT = 26,                   /* OPER_AT  */
  YYSYMBOL_OPER_INC = 27,                  /* OPER_INC  */
  YYSYMBOL_OPER_DEC = 28,                  /* OPER_DEC  */
  YYSYMBOL_OPER_AND = 29,                  /* OPER_AND  */
  YYSYMBOL_OPER_OR = 30,                   /* OPER_OR  */
  YYSYMBOL_OPER_NOT = 31,                  /* OPER_NOT  */
  YYSYMBOL_LSQ_BRKT = 32,                  /* LSQ_BRKT  */
  YYSYMBOL_RSQ_BRKT = 33,                  /* RSQ_BRKT  */
  YYSYMBOL_LCRLY_BRKT = 34,                /* LCRLY_BRKT  */
  YYSYMBOL_RCRLY_BRKT = 35,                /* RCRLY_BRKT  */
  YYSYMBOL_LPAREN = 36,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 37,                    /* RPAREN  */
  YYSYMBOL_COMMA = 38,                     /* COMMA  */
  YYSYMBOL_SEMICLN = 39,                   /* SEMICLN  */
  YYSYMBOL_ERROR = 40,                     /* ERROR  */
  YYSYMBOL_LOWER_THAN_ELSE = 41,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_program = 43,                   /* program  */
  YYSYMBOL_declList = 44,                  /* declList  */
  YYSYMBOL_decl = 45,                      /* decl  */
  YYSYMBOL_varDecl = 46,                   /* varDecl  */
  YYSYMBOL_typeSpecifier = 47,             /* typeSpecifier  */
  YYSYMBOL_funDecl = 48,                   /* funDecl  */
  YYSYMBOL_funcTypeName = 49,              /* funcTypeName  */
  YYSYMBOL_formalDeclList = 50,            /* formalDeclList  */
  YYSYMBOL_formalDecl = 51,                /* formalDecl  */
  YYSYMBOL_arrayDecl = 52,                 /* arrayDecl  */
  YYSYMBOL_funBody = 53,                   /* funBody  */
  YYSYMBOL_localDeclList = 54,             /* localDeclList  */
  YYSYMBOL_statementList = 55,             /* statementList  */
  YYSYMBOL_statement = 56,                 /* statement  */
  YYSYMBOL_compoundStmt = 57,              /* compoundStmt  */
  YYSYMBOL_assignStmt = 58,                /* assignStmt  */
  YYSYMBOL_condStmt = 59,                  /* condStmt  */
  YYSYMBOL_loopStmt = 60,                  /* loopStmt  */
  YYSYMBOL_returnStmt = 61,                /* returnStmt  */
  YYSYMBOL_var = 62,                       /* var  */
  YYSYMBOL_expression = 63,                /* expression  */
  YYSYMBOL_relop = 64,                     /* relop  */
  YYSYMBOL_addExpr = 65,                   /* addExpr  */
  YYSYMBOL_addop = 66,                     /* addop  */
  YYSYMBOL_term = 67,                      /* term  */
  YYSYMBOL_mulop = 68,                     /* mulop  */
  YYSYMBOL_factor = 69,                    /* factor  */
  YYSYMBOL_funcCallExpr = 70,              /* funcCallExpr  */
  YYSYMBOL_argList = 71                    /* argList  */
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
#define YYLAST   144

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  111

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    76,    76,    85,    91,   100,   106,   114,   127,   154,
     158,   162,   168,   186,   205,   230,   236,   245,   260,   279,
     285,   295,   298,   308,   311,   320,   326,   332,   338,   344,
     352,   360,   367,   375,   382,   392,   401,   405,   413,   431,
     452,   458,   468,   469,   470,   471,   472,   473,   476,   482,
     492,   493,   496,   502,   512,   513,   516,   522,   528,   534,
     541,   548,   558,   577,   597,   603
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
  "INTCONST", "CHARCONST", "KWD_IF", "KWD_ELSE", "KWD_WHILE", "KWD_INT",
  "KWD_CHAR", "KWD_RETURN", "KWD_VOID", "OPER_ADD", "OPER_SUB", "OPER_MUL",
  "OPER_DIV", "OPER_MOD", "OPER_LT", "OPER_GT", "OPER_LTE", "OPER_GTE",
  "OPER_EQ", "OPER_NEQ", "OPER_ASGN", "OPER_AT", "OPER_INC", "OPER_DEC",
  "OPER_AND", "OPER_OR", "OPER_NOT", "LSQ_BRKT", "RSQ_BRKT", "LCRLY_BRKT",
  "RCRLY_BRKT", "LPAREN", "RPAREN", "COMMA", "SEMICLN", "ERROR",
  "LOWER_THAN_ELSE", "$accept", "program", "declList", "decl", "varDecl",
  "typeSpecifier", "funDecl", "funcTypeName", "formalDeclList",
  "formalDecl", "arrayDecl", "funBody", "localDeclList", "statementList",
  "statement", "compoundStmt", "assignStmt", "condStmt", "loopStmt",
  "returnStmt", "var", "expression", "relop", "addExpr", "addop", "term",
  "mulop", "factor", "funcCallExpr", "argList", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-45)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      65,   -45,   -45,   -45,     2,    65,   -45,   -45,    42,   -45,
      20,   -45,   -45,    32,    33,    53,   -45,    38,    74,    66,
      69,    72,    65,   -45,    76,    38,    65,    70,    65,   127,
      19,    99,   -45,   -45,   -45,   -45,   -45,    32,   -20,   -45,
     -45,   -45,    95,    97,     1,    19,    29,   101,    19,   -45,
     -45,   -45,   -45,   -45,   109,    28,    -1,    44,   -45,   -45,
     -45,    29,     5,    29,    29,   -45,   -45,    61,   102,    73,
     -45,   -45,    29,   -45,   -45,   -45,   -45,   -45,   -45,   -45,
      29,   -45,   -45,    29,   -45,   -45,    29,    24,   -45,   104,
      64,    92,    98,   -45,   -45,   -45,    67,    -1,    44,   -45,
     -45,   -45,    29,    19,    19,   -45,   104,   130,   -45,    19,
     -45
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,    11,     0,     2,     3,     5,     0,     6,
       0,     1,     4,    14,     0,     0,     7,     0,     0,     0,
      15,     0,    21,    13,    17,     0,     0,     0,    21,     0,
      23,     0,    18,    12,    16,     8,    22,     0,    38,    61,
      59,    60,     0,     0,     0,    23,     0,     0,    23,    26,
      25,    27,    28,    29,    57,     0,    40,    48,    52,    58,
      19,     0,     0,     0,     0,    36,    57,     0,     0,     0,
      20,    24,     0,    43,    44,    42,    45,    46,    47,    32,
       0,    50,    51,     0,    54,    55,     0,     0,    63,    64,
       0,     0,     0,    37,    30,    56,     0,    41,    49,    53,
      39,    62,     0,     0,     0,    31,    65,    33,    35,     0,
      34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -45,   -45,   -45,   134,    41,    40,   -45,   -45,   114,   -45,
     -45,   116,   115,   -18,    -5,   -45,   -45,   -45,   -45,   -45,
     -30,   -43,   -45,   -44,   -45,    59,   -45,    58,   -45,   -45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,     9,    10,    19,    20,
      32,    23,    30,    47,    48,    49,    50,    51,    52,    53,
      66,    55,    80,    56,    83,    57,    86,    58,    59,    90
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      54,    67,    11,    69,    38,    39,    40,    41,    38,    39,
      40,    41,    61,    81,    82,    54,    62,    87,    54,    89,
      91,    92,    38,    39,    40,    41,    42,    68,    43,    96,
      71,    44,    38,    39,    40,    41,    97,    46,    81,    82,
      65,    46,    88,     1,     2,    13,     3,    73,    74,    75,
      76,    77,    78,    45,    18,    46,    14,   100,    21,   106,
      84,    85,    29,    28,    15,    46,    18,    79,    29,    28,
      17,    16,    22,    54,    54,     1,     2,    24,     3,    54,
      73,    74,    75,    76,    77,    78,    73,    74,    75,    76,
      77,    78,    73,    74,    75,    76,    77,    78,   107,   108,
      93,   101,   102,    25,   110,    27,   105,    26,    31,    35,
      95,    73,    74,    75,    76,    77,    78,    73,    74,    75,
      76,    77,    78,    73,    74,    75,    76,    77,    78,   103,
      37,    63,    60,    64,    72,   104,    70,    94,   109,    12,
      34,    33,    98,    36,    99
};

static const yytype_int8 yycheck[] =
{
      30,    44,     0,    46,     3,     4,     5,     6,     3,     4,
       5,     6,    32,    14,    15,    45,    36,    61,    48,    62,
      63,    64,     3,     4,     5,     6,     7,    45,     9,    72,
      48,    12,     3,     4,     5,     6,    80,    36,    14,    15,
      39,    36,    37,    10,    11,     3,    13,    19,    20,    21,
      22,    23,    24,    34,    14,    36,    36,    33,     5,   102,
      16,    17,    22,    22,    32,    36,    26,    39,    28,    28,
      37,    39,    34,   103,   104,    10,    11,     3,    13,   109,
      19,    20,    21,    22,    23,    24,    19,    20,    21,    22,
      23,    24,    19,    20,    21,    22,    23,    24,   103,   104,
      39,    37,    38,    37,   109,    33,    39,    38,    32,    39,
      37,    19,    20,    21,    22,    23,    24,    19,    20,    21,
      22,    23,    24,    19,    20,    21,    22,    23,    24,    37,
       3,    36,    33,    36,    25,    37,    35,    35,     8,     5,
      26,    25,    83,    28,    86
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    11,    13,    43,    44,    45,    46,    47,    48,
      49,     0,    45,     3,    36,    32,    39,    37,    47,    50,
      51,     5,    34,    53,     3,    37,    38,    33,    46,    47,
      54,    32,    52,    53,    50,    39,    54,     3,     3,     4,
       5,     6,     7,     9,    12,    34,    36,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    65,    67,    69,    70,
      33,    32,    36,    36,    36,    39,    62,    63,    55,    63,
      35,    55,    25,    19,    20,    21,    22,    23,    24,    39,
      64,    14,    15,    66,    16,    17,    68,    65,    37,    63,
      71,    63,    63,    39,    35,    37,    63,    65,    67,    69,
      33,    37,    38,    37,    37,    39,    63,    56,    56,     8,
      56
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    46,    46,    47,
      47,    47,    48,    48,    49,    50,    50,    51,    51,    52,
      53,    54,    54,    55,    55,    56,    56,    56,    56,    56,
      57,    58,    58,    59,    59,    60,    61,    61,    62,    62,
      63,    63,    64,    64,    64,    64,    64,    64,    65,    65,
      66,    66,    67,    67,    68,    68,    69,    69,    69,    69,
      69,    69,    70,    70,    71,    71
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     6,     1,
       1,     1,     5,     4,     2,     1,     3,     2,     3,     2,
       4,     0,     2,     0,     2,     1,     1,     1,     1,     1,
       3,     4,     2,     5,     7,     5,     2,     3,     1,     4,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     4,     3,     1,     3
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
#line 1374 "y.tab.c"
    break;

  case 3: /* declList: decl  */
#line 86 "../src/parser.y"
    {
        tree* declListNode = maketree(DECLLIST);
        addChild(declListNode, (yyvsp[0].node));
        (yyval.node) = declListNode;
    }
#line 1384 "y.tab.c"
    break;

  case 4: /* declList: declList decl  */
#line 92 "../src/parser.y"
    {
        tree* declListNode = maketree(DECLLIST);
        addChild(declListNode, (yyvsp[-1].node));
        addChild(declListNode, (yyvsp[0].node));
        (yyval.node) = declListNode;
    }
#line 1395 "y.tab.c"
    break;

  case 5: /* decl: varDecl  */
#line 101 "../src/parser.y"
    {
        tree* declNode = maketree(DECL);
        addChild(declNode, (yyvsp[0].node));
        (yyval.node) = declNode;
    }
#line 1405 "y.tab.c"
    break;

  case 6: /* decl: funDecl  */
#line 107 "../src/parser.y"
    {
        tree* declNode = maketree(DECL);
        addChild(declNode, (yyvsp[0].node));
        (yyval.node) = declNode;
    }
#line 1415 "y.tab.c"
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
#line 1432 "y.tab.c"
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
#line 1461 "y.tab.c"
    break;

  case 9: /* typeSpecifier: KWD_INT  */
#line 155 "../src/parser.y"
    {
        (yyval.node) = maketreeWithVal(TYPESPEC, INT_TYPE);
    }
#line 1469 "y.tab.c"
    break;

  case 10: /* typeSpecifier: KWD_CHAR  */
#line 159 "../src/parser.y"
    {
        (yyval.node) = maketreeWithVal(TYPESPEC, CHAR_TYPE);
    }
#line 1477 "y.tab.c"
    break;

  case 11: /* typeSpecifier: KWD_VOID  */
#line 163 "../src/parser.y"
    {
        (yyval.node) = maketreeWithVal(TYPESPEC, VOID_TYPE);
    }
#line 1485 "y.tab.c"
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
#line 1507 "y.tab.c"
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
#line 1528 "y.tab.c"
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
#line 1555 "y.tab.c"
    break;

  case 15: /* formalDeclList: formalDecl  */
#line 231 "../src/parser.y"
    {
        tree* formalDeclListNode = maketree(FORMALDECLLIST);
        addChild(formalDeclListNode, (yyvsp[0].node));
        (yyval.node) = formalDeclListNode;
    }
#line 1565 "y.tab.c"
    break;

  case 16: /* formalDeclList: formalDecl COMMA formalDeclList  */
#line 237 "../src/parser.y"
    {
        tree* formalDeclListNode = maketree(FORMALDECLLIST);
        addChild(formalDeclListNode, (yyvsp[-2].node));
        addChild(formalDeclListNode, (yyvsp[0].node));
        (yyval.node) = formalDeclListNode;
    }
#line 1576 "y.tab.c"
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
#line 1595 "y.tab.c"
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
#line 1616 "y.tab.c"
    break;

  case 19: /* arrayDecl: LSQ_BRKT RSQ_BRKT  */
#line 280 "../src/parser.y"
    {
        (yyval.node) = maketree(ARRAYDECL);
    }
#line 1624 "y.tab.c"
    break;

  case 20: /* funBody: LCRLY_BRKT localDeclList statementList RCRLY_BRKT  */
#line 286 "../src/parser.y"
    {
        tree* funBodyNode = maketree(FUNBODY);
        if ((yyvsp[-2].node) != NULL) addChild(funBodyNode, (yyvsp[-2].node));
        if ((yyvsp[-1].node) != NULL) addChild(funBodyNode, (yyvsp[-1].node));
        (yyval.node) = funBodyNode;
    }
#line 1635 "y.tab.c"
    break;

  case 21: /* localDeclList: %empty  */
#line 295 "../src/parser.y"
    {
        (yyval.node) = NULL;
    }
#line 1643 "y.tab.c"
    break;

  case 22: /* localDeclList: varDecl localDeclList  */
#line 299 "../src/parser.y"
    {
        tree* localDeclListNode = maketree(LOCALDECLLIST);
        addChild(localDeclListNode, (yyvsp[-1].node));
        if ((yyvsp[0].node) != NULL) addChild(localDeclListNode, (yyvsp[0].node));
        (yyval.node) = localDeclListNode;
    }
#line 1654 "y.tab.c"
    break;

  case 23: /* statementList: %empty  */
#line 308 "../src/parser.y"
    {
        (yyval.node) = NULL;
    }
#line 1662 "y.tab.c"
    break;

  case 24: /* statementList: statement statementList  */
#line 312 "../src/parser.y"
    {
        tree* stmtListNode = maketree(STATEMENTLIST);
        addChild(stmtListNode, (yyvsp[-1].node));
        if ((yyvsp[0].node) != NULL) addChild(stmtListNode, (yyvsp[0].node));
        (yyval.node) = stmtListNode;
    }
#line 1673 "y.tab.c"
    break;

  case 25: /* statement: assignStmt  */
#line 321 "../src/parser.y"
    {
        tree* stmtNode = maketree(STATEMENT);
        addChild(stmtNode, (yyvsp[0].node));
        (yyval.node) = stmtNode;
    }
#line 1683 "y.tab.c"
    break;

  case 26: /* statement: compoundStmt  */
#line 327 "../src/parser.y"
    {
        tree* stmtNode = maketree(STATEMENT);
        addChild(stmtNode, (yyvsp[0].node));
        (yyval.node) = stmtNode;
    }
#line 1693 "y.tab.c"
    break;

  case 27: /* statement: condStmt  */
#line 333 "../src/parser.y"
    {
        tree* stmtNode = maketree(STATEMENT);
        addChild(stmtNode, (yyvsp[0].node));
        (yyval.node) = stmtNode;
    }
#line 1703 "y.tab.c"
    break;

  case 28: /* statement: loopStmt  */
#line 339 "../src/parser.y"
    {
        tree* stmtNode = maketree(STATEMENT);
        addChild(stmtNode, (yyvsp[0].node));
        (yyval.node) = stmtNode;
    }
#line 1713 "y.tab.c"
    break;

  case 29: /* statement: returnStmt  */
#line 345 "../src/parser.y"
    {
        tree* stmtNode = maketree(STATEMENT);
        addChild(stmtNode, (yyvsp[0].node));
        (yyval.node) = stmtNode;
    }
#line 1723 "y.tab.c"
    break;

  case 30: /* compoundStmt: LCRLY_BRKT statementList RCRLY_BRKT  */
#line 353 "../src/parser.y"
    {
        tree* compStmtNode = maketree(COMPOUNDSTMT);
        if ((yyvsp[-1].node) != NULL) addChild(compStmtNode, (yyvsp[-1].node));
        (yyval.node) = compStmtNode;
    }
#line 1733 "y.tab.c"
    break;

  case 31: /* assignStmt: var OPER_ASGN expression SEMICLN  */
#line 361 "../src/parser.y"
    {
        tree* assignNode = maketree(ASSIGNSTMT);
        addChild(assignNode, (yyvsp[-3].node));
        addChild(assignNode, (yyvsp[-1].node));
        (yyval.node) = assignNode;
    }
#line 1744 "y.tab.c"
    break;

  case 32: /* assignStmt: expression SEMICLN  */
#line 368 "../src/parser.y"
    {
        tree* assignNode = maketree(ASSIGNSTMT);
        addChild(assignNode, (yyvsp[-1].node));
        (yyval.node) = assignNode;
    }
#line 1754 "y.tab.c"
    break;

  case 33: /* condStmt: KWD_IF LPAREN expression RPAREN statement  */
#line 376 "../src/parser.y"
    {
        tree* condNode = maketree(CONDSTMT);
        addChild(condNode, (yyvsp[-2].node));
        addChild(condNode, (yyvsp[0].node));
        (yyval.node) = condNode;
    }
#line 1765 "y.tab.c"
    break;

  case 34: /* condStmt: KWD_IF LPAREN expression RPAREN statement KWD_ELSE statement  */
#line 383 "../src/parser.y"
    {
        tree* condNode = maketree(CONDSTMT);
        addChild(condNode, (yyvsp[-4].node));
        addChild(condNode, (yyvsp[-2].node));
        addChild(condNode, (yyvsp[0].node));
        (yyval.node) = condNode;
    }
#line 1777 "y.tab.c"
    break;

  case 35: /* loopStmt: KWD_WHILE LPAREN expression RPAREN statement  */
#line 393 "../src/parser.y"
    {
        tree* loopNode = maketree(LOOPSTMT);
        addChild(loopNode, (yyvsp[-2].node));
        addChild(loopNode, (yyvsp[0].node));
        (yyval.node) = loopNode;
    }
#line 1788 "y.tab.c"
    break;

  case 36: /* returnStmt: KWD_RETURN SEMICLN  */
#line 402 "../src/parser.y"
    {
        (yyval.node) = maketree(RETURNSTMT);
    }
#line 1796 "y.tab.c"
    break;

  case 37: /* returnStmt: KWD_RETURN expression SEMICLN  */
#line 406 "../src/parser.y"
    {
        tree* returnNode = maketree(RETURNSTMT);
        addChild(returnNode, (yyvsp[-1].node));
        (yyval.node) = returnNode;
    }
#line 1806 "y.tab.c"
    break;

  case 38: /* var: ID  */
#line 414 "../src/parser.y"
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
#line 1828 "y.tab.c"
    break;

  case 39: /* var: ID LSQ_BRKT addExpr RSQ_BRKT  */
#line 432 "../src/parser.y"
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
#line 1851 "y.tab.c"
    break;

  case 40: /* expression: addExpr  */
#line 453 "../src/parser.y"
    {
        tree* exprNode = maketree(EXPRESSION);
        addChild(exprNode, (yyvsp[0].node));
        (yyval.node) = exprNode;
    }
#line 1861 "y.tab.c"
    break;

  case 41: /* expression: expression relop addExpr  */
#line 459 "../src/parser.y"
    {
        tree* exprNode = maketree(EXPRESSION);
        addChild(exprNode, (yyvsp[-2].node));
        addChild(exprNode, (yyvsp[-1].node));
        addChild(exprNode, (yyvsp[0].node));
        (yyval.node) = exprNode;
    }
#line 1873 "y.tab.c"
    break;

  case 42: /* relop: OPER_LTE  */
#line 468 "../src/parser.y"
                  { (yyval.node) = maketreeWithVal(RELOP, LTE_OP); }
#line 1879 "y.tab.c"
    break;

  case 43: /* relop: OPER_LT  */
#line 469 "../src/parser.y"
                  { (yyval.node) = maketreeWithVal(RELOP, LT_OP); }
#line 1885 "y.tab.c"
    break;

  case 44: /* relop: OPER_GT  */
#line 470 "../src/parser.y"
                  { (yyval.node) = maketreeWithVal(RELOP, GT_OP); }
#line 1891 "y.tab.c"
    break;

  case 45: /* relop: OPER_GTE  */
#line 471 "../src/parser.y"
                  { (yyval.node) = maketreeWithVal(RELOP, GTE_OP); }
#line 1897 "y.tab.c"
    break;

  case 46: /* relop: OPER_EQ  */
#line 472 "../src/parser.y"
                  { (yyval.node) = maketreeWithVal(RELOP, EQ_OP); }
#line 1903 "y.tab.c"
    break;

  case 47: /* relop: OPER_NEQ  */
#line 473 "../src/parser.y"
                  { (yyval.node) = maketreeWithVal(RELOP, NEQ_OP); }
#line 1909 "y.tab.c"
    break;

  case 48: /* addExpr: term  */
#line 477 "../src/parser.y"
    {
        tree* addExprNode = maketree(ADDEXPR);
        addChild(addExprNode, (yyvsp[0].node));
        (yyval.node) = addExprNode;
    }
#line 1919 "y.tab.c"
    break;

  case 49: /* addExpr: addExpr addop term  */
#line 483 "../src/parser.y"
    {
        tree* addExprNode = maketree(ADDEXPR);
        addChild(addExprNode, (yyvsp[-2].node));
        addChild(addExprNode, (yyvsp[-1].node));
        addChild(addExprNode, (yyvsp[0].node));
        (yyval.node) = addExprNode;
    }
#line 1931 "y.tab.c"
    break;

  case 50: /* addop: OPER_ADD  */
#line 492 "../src/parser.y"
                  { (yyval.node) = maketreeWithVal(ADDOP, 0); }
#line 1937 "y.tab.c"
    break;

  case 51: /* addop: OPER_SUB  */
#line 493 "../src/parser.y"
                  { (yyval.node) = maketreeWithVal(ADDOP, 1); }
#line 1943 "y.tab.c"
    break;

  case 52: /* term: factor  */
#line 497 "../src/parser.y"
    {
        tree* termNode = maketree(TERM);
        addChild(termNode, (yyvsp[0].node));
        (yyval.node) = termNode;
    }
#line 1953 "y.tab.c"
    break;

  case 53: /* term: term mulop factor  */
#line 503 "../src/parser.y"
    {
        tree* termNode = maketree(TERM);
        addChild(termNode, (yyvsp[-2].node));
        addChild(termNode, (yyvsp[-1].node));
        addChild(termNode, (yyvsp[0].node));
        (yyval.node) = termNode;
    }
#line 1965 "y.tab.c"
    break;

  case 54: /* mulop: OPER_MUL  */
#line 512 "../src/parser.y"
                  { (yyval.node) = maketreeWithVal(MULOP, 2); }
#line 1971 "y.tab.c"
    break;

  case 55: /* mulop: OPER_DIV  */
#line 513 "../src/parser.y"
                  { (yyval.node) = maketreeWithVal(MULOP, 3); }
#line 1977 "y.tab.c"
    break;

  case 56: /* factor: LPAREN expression RPAREN  */
#line 517 "../src/parser.y"
    {
        tree* factorNode = maketree(FACTOR);
        addChild(factorNode, (yyvsp[-1].node));
        (yyval.node) = factorNode;
    }
#line 1987 "y.tab.c"
    break;

  case 57: /* factor: var  */
#line 523 "../src/parser.y"
    {
        tree* factorNode = maketree(FACTOR);
        addChild(factorNode, (yyvsp[0].node));
        (yyval.node) = factorNode;
    }
#line 1997 "y.tab.c"
    break;

  case 58: /* factor: funcCallExpr  */
#line 529 "../src/parser.y"
    {
        tree* factorNode = maketree(FACTOR);
        addChild(factorNode, (yyvsp[0].node));
        (yyval.node) = factorNode;
    }
#line 2007 "y.tab.c"
    break;

  case 59: /* factor: INTCONST  */
#line 535 "../src/parser.y"
    {
        tree* factorNode = maketree(FACTOR);
        tree* intNode = maketreeWithVal(INTEGER, (yyvsp[0].value));
        addChild(factorNode, intNode);
        (yyval.node) = factorNode;
    }
#line 2018 "y.tab.c"
    break;

  case 60: /* factor: CHARCONST  */
#line 542 "../src/parser.y"
    {
        tree* factorNode = maketree(FACTOR);
        tree* charNode = maketreeWithVal(CHAR_NODE, (yyvsp[0].value));
        addChild(factorNode, charNode);
        (yyval.node) = factorNode;
    }
#line 2029 "y.tab.c"
    break;

  case 61: /* factor: STRCONST  */
#line 549 "../src/parser.y"
    {
        tree* factorNode = maketree(FACTOR);
        tree* strNode = maketree(STRING_NODE);
        strNode->name = strdup((yyvsp[0].strval));
        addChild(factorNode, strNode);
        (yyval.node) = factorNode;
    }
#line 2041 "y.tab.c"
    break;

  case 62: /* funcCallExpr: ID LPAREN argList RPAREN  */
#line 559 "../src/parser.y"
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
#line 2064 "y.tab.c"
    break;

  case 63: /* funcCallExpr: ID LPAREN RPAREN  */
#line 578 "../src/parser.y"
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
#line 2086 "y.tab.c"
    break;

  case 64: /* argList: expression  */
#line 598 "../src/parser.y"
    {
        tree* argListNode = maketree(ARGLIST);
        addChild(argListNode, (yyvsp[0].node));
        (yyval.node) = argListNode;
    }
#line 2096 "y.tab.c"
    break;

  case 65: /* argList: argList COMMA expression  */
#line 604 "../src/parser.y"
    {
        tree* argListNode = maketree(ARGLIST);
        addChild(argListNode, (yyvsp[-2].node));
        addChild(argListNode, (yyvsp[0].node));
        (yyval.node) = argListNode;
    }
#line 2107 "y.tab.c"
    break;


#line 2111 "y.tab.c"

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

#line 612 "../src/parser.y"


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
