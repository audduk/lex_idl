%token NUMBER LETTER ENDL PLUS MINUS MUL DIV L_BRAC R_BRAC
%left PLUS MINUS
%left MUL DIV

%{
#include <stdio.h>
#include <stdlib.h>

#define YYDEBUG 0

extern int yylex();
void yyerror(const char *);
int yyparse();

int regs[26];
%}

%%
calc: /*пустой список операторов*/
| calc stat ENDL {printf("result = %d\n", $2);}
| calc stat error ENDL {yyerrok;}
;

stat: expr
| LETTER '=' expr { printf("stat"); regs[$1]=$3; $$=$3; }
;

expr:
L_BRAC expr R_BRAC {$$=$2; printf("(%d);", $$);}
| expr PLUS expr   {$$=$1+$3; printf("%d+%d=%d;",$1,$3,$$);}
| expr MINUS expr  {$$=$1-$3; printf("%d-%d=%d;",$1,$3,$$);}
| expr MUL expr    {$$=$1*$3; printf("%d*%d=%d;",$1,$3,$$);}
| expr DIV expr    {$$=$1/$3; printf("%d/%d=%d;",$1,$3,$$);}
| LETTER           {$$=regs[$1]; printf("letter");}
| NUMBER {/*printf("NUMBER ");*/}
;

%%
void yyerror(const char * mess) { fprintf(stderr, "%s\n", mess); }

int main() { yydebug = 1; return yyparse(); }