%start COMMENT

%{

#include <io.h>
#include "services_yacc.h"
#include "analizer.h"

int linenum = 0; // !!! ВНИМАНИЕ - перед первым вызовом yylex() необходимо установить в 1, linenum==0 - признак встроенных типов

%}

LETTER [_A-Za-z]
ANY {LETTER}|[0-9]|[:space:]|[:punct:]

IDENT {LETTER}({LETTER}|[0-9])*

%%

enum        return TOK_ENUM;
const       return TOK_CONST;
struct      return TOK_STRUCT;
service     return TOK_SERVICE;

sequence    return TOK_SEQUENCE;
void        return TOK_VOID;

[{}();,<>\=]  return yytext[0];

[ \t]       /* eatup spaces */
"//".*$     /* eatup simple comments */
[\n]        ++linenum;

{IDENT} {
    yylval = appendIdent(yytext); // position of new ident in vector
    return TOK_IDENT;
}

-?[0-9]+            yylval = atoi(yytext); return TOK_INT;
-?[0-9]+\.[0-9]*    yylval = appendFloat(atof(yytext)); return TOK_FLOAT;
'{ANY}'             yylval = appendString(yytext); return TOK_STR;

"/*"          BEGIN COMMENT; /* start comment section */
<COMMENT>[^*\n]*|[^/]        /* eatup comment section */
<COMMENT><<EOF>>    yyerror("Unterminated comment section!"); BEGIN INITIAL;
<COMMENT>"*/" BEGIN INITIAL; /* stop comment section  */

%%

int yywrap() { return 1; }

//int main() { while(yylex()) ; printf("\n"); return 1; }
