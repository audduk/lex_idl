%{
#include "calc_yacc.h"
extern int yylval;
%}

%%

"����" return PLUS;

[0-9]+ {
    yylval = atoi(yytext); /*����������� � �����*/
    return NUMBER;
};
[a-z] {
    yylval = yytext[0]-'a'; /*����������� � �����, �=0 ...*/
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
