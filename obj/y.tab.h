/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 155 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
