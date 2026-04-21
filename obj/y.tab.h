/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     STRCONST = 259,
     INTCONST = 260,
     CHARCONST = 261,
     KWD_IF = 262,
     KWD_ELSE = 263,
     KWD_WHILE = 264,
     KWD_INT = 265,
     KWD_CHAR = 266,
     KWD_RETURN = 267,
     KWD_VOID = 268,
     OPER_ADD = 269,
     OPER_SUB = 270,
     OPER_MUL = 271,
     OPER_DIV = 272,
     OPER_MOD = 273,
     OPER_LT = 274,
     OPER_GT = 275,
     OPER_LTE = 276,
     OPER_GTE = 277,
     OPER_EQ = 278,
     OPER_NEQ = 279,
     OPER_ASGN = 280,
     OPER_AT = 281,
     OPER_INC = 282,
     OPER_DEC = 283,
     OPER_AND = 284,
     OPER_OR = 285,
     OPER_NOT = 286,
     LSQ_BRKT = 287,
     RSQ_BRKT = 288,
     LCRLY_BRKT = 289,
     RCRLY_BRKT = 290,
     LPAREN = 291,
     RPAREN = 292,
     COMMA = 293,
     SEMICLN = 294,
     ERROR = 295,
     LOWER_THAN_ELSE = 296
   };
#endif
/* Tokens.  */
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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 25 "src/parser.y"
{
    int value;
    struct treenode *node;
    char *strval;
}
/* Line 1529 of yacc.c.  */
#line 137 "obj/y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

