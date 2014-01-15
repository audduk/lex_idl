%{
#include "calc_yacc.h"
extern int yylval;
%}

%%

[0-9]+ {
    yylval = atoi(yytext); /*преобразуем к числу*/
    return NUMBER;
};
[a-z] {
    yylval = yytext[0]-'a'; /*преобразуем к числу, а=0 ...*/
    return LETTER;
};
[\n]+ {
    return ENDL;
};

"+" return PLUS;
"-" return MINUS;
"*" return MUL;
"/" return DIV;
"(" return L_BRAC;
")" return R_BRAC;

%%

int yywrap() { return 1; }
