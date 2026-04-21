/* definitions */

%x COMMENT
%x STR
%x STR_ERR

%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"

 /* integers to track line and column numbers */
int scancol = 1;
int yycol = 1;
int scanlineno = 1;

 /* char pointer to pass error messages to driver.c */
char *scan_err;

 /* functions to update line and column numbers */
void updateCol();

static int comment_start_line, comment_start_col;
static int string_start_line, string_start_col;

static char strbuf[4096];
static int  stridx;

%}

newline         \n
whitespace      [ \t]+
integer         [1-9][0-9]*|0
integerlead0    0[0-9]+
character       \'[^\'\n]\'

identifier      [a-zA-Z][a-zA-Z0-9]*
illidentifier   [0-9]+[a-zA-Z][a-zA-Z0-9]*

%%

 /* rules */

 /* Comment Handling */

"/*" {
    comment_start_line = scanlineno;
    comment_start_col  = scancol;
    scancol += yyleng;
    BEGIN(COMMENT);
}

<COMMENT>"*/" {
    scancol += yyleng;
    BEGIN(INITIAL);
}

<COMMENT>\n {
    scanlineno++;
    scancol = 1;
}

<COMMENT>. {
    scancol += yyleng;
}

<COMMENT><<EOF>> {
    scan_err  = "Unterminated comment";
    yylineno = comment_start_line;
    yycol    = comment_start_col;
    BEGIN(INITIAL);
    return ERROR;
}

 /* String Handling*/

\" {
    string_start_line = scanlineno;
    string_start_col  = scancol;
    stridx = 0;
    scancol += yyleng;
    BEGIN(STR);
}

<STR>\" {
    strbuf[stridx] = '\0';
    yylval.strval = strdup(strbuf);  /* ADD: Pass string to parser */

    yylineno = string_start_line;
    yycol    = string_start_col;

    scancol += yyleng;
    BEGIN(INITIAL);
    return STRCONST;
}

<STR>\n {
    scan_err  = "Unterminated string";
    yylineno = string_start_line;
    yycol    = string_start_col;
    scanlineno++;
    scancol = 1;
    BEGIN(STR_ERR);
    return ERROR;
}

<STR>\\[nt\"\\] {
    char e = yytext[1];
    if (e == 'n')       strbuf[stridx++] = '\n';
    else if (e == 't')  strbuf[stridx++] = '\t';
    else if (e == '"')  strbuf[stridx++] = '"';
    else                strbuf[stridx++] = '\\';

    scancol += yyleng;
}

<STR>\\. {
    scan_err  = "Unrecognized escape character";
    yylineno = scanlineno;
    yycol    = scancol;
    scancol += yyleng;
    BEGIN(STR_ERR);
    return ERROR;
}

<STR>[^\\\"\n]+ {
    int i;
    for (i = 0; i < yyleng; i++) {
        strbuf[stridx++] = yytext[i];
    }
    scancol += yyleng;
}

<STR><<EOF>> {
    scan_err  = "Unterminated string";
    yylineno = string_start_line;
    yycol    = string_start_col;
    BEGIN(INITIAL);
    return ERROR;
}

<STR_ERR>\"       { scancol += yyleng; BEGIN(INITIAL); }
<STR_ERR>\n       { scanlineno++; scancol = 1; }
<STR_ERR><<EOF>>  { BEGIN(INITIAL); }
<STR_ERR>.        { scancol += yyleng; }

 /* Keywords */
"if"      { updateCol(); return KWD_IF; }
"else"    { updateCol(); return KWD_ELSE; }
"while"   { updateCol(); return KWD_WHILE; }
"int"     { updateCol(); return KWD_INT; }
"char"    { updateCol(); return KWD_CHAR; }
"return"  { updateCol(); return KWD_RETURN; }
"void"    { updateCol(); return KWD_VOID; }

 /* Operators - Multi-character first */
"++"      { updateCol(); return OPER_INC; }
"--"      { updateCol(); return OPER_DEC; }
"&&"      { updateCol(); return OPER_AND; }
"||"      { updateCol(); return OPER_OR; }
"<="      { updateCol(); return OPER_LTE; }
">="      { updateCol(); return OPER_GTE; }
"=="      { updateCol(); return OPER_EQ; }
"!="      { updateCol(); return OPER_NEQ; }

 /* Operators - Single character */
"+"       { updateCol(); return OPER_ADD; }
"-"       { updateCol(); return OPER_SUB; }
"*"       { updateCol(); return OPER_MUL; }
"/"       { updateCol(); return OPER_DIV; }
"%"       { updateCol(); return OPER_MOD; }
"<"       { updateCol(); return OPER_LT; }
">"       { updateCol(); return OPER_GT; }
"="       { updateCol(); return OPER_ASGN; }
"!"       { updateCol(); return OPER_NOT; }
"@"       { updateCol(); return OPER_AT; }

 /* Brackets and Parentheses */
"["       { updateCol(); return LSQ_BRKT; }
"]"       { updateCol(); return RSQ_BRKT; }
"{"       { updateCol(); return LCRLY_BRKT; }
"}"       { updateCol(); return RCRLY_BRKT; }
"("       { updateCol(); return LPAREN; }
")"       { updateCol(); return RPAREN; }

 /* Punctuation */
","       { updateCol(); return COMMA; }
";"       { updateCol(); return SEMICLN; }

 /* Identifiers */
{identifier}    { 
    updateCol(); 
    yylval.strval = strdup(yytext);  /* ADD: Pass identifier name to parser */
    return ID; 
}

{illidentifier} { 
    updateCol(); 
    scan_err = "Identifier begins with a number"; 
    return ERROR; 
}

 /* Constants */
{integer}       { 
    updateCol(); 
    yylval.value = atoi(yytext);  /* ADD: Pass integer value to parser */
    return INTCONST; 
}

{integerlead0}  { 
    updateCol(); 
    scan_err = "Integer with leading zero"; 
    return ERROR; 
}

 /* Bad character constants */
\'\'                { updateCol(); scan_err = "Illegal token"; return ERROR; }
\'[^\'\n]{2,}\'     { updateCol(); scan_err = "Illegal token"; return ERROR; }
\'\\[^\'\n]\'       { updateCol(); scan_err = "Illegal token"; return ERROR; }

{character} {
    updateCol();
    unsigned char c = (unsigned char)yytext[1];
    yylval.value = (int)c;  /* ADD: Pass character ASCII value to parser */
    return CHARCONST;
}

 /* Other */
{newline}       { scanlineno++; scancol = 1; }
{whitespace}    { updateCol(); }
.               { updateCol(); scan_err = "Illegal token"; return ERROR; }

%%

/* user routines */

void updateCol(){
    scan_err = NULL;
    yycol = scancol;
    yylineno = scanlineno;
    scancol += yyleng;
}

int yywrap(){
    return 1;
}