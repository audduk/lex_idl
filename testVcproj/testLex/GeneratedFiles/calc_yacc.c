#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
#define YYPREFIX "yy"
#line 6 "d:\Projects\lex\testVcproj\testLex\calc.y"
#include <stdio.h>
#include <stdlib.h>

#define YYDEBUG 0

extern int yylex();
void yyerror(const char *);
int yyparse();

int regs[26];
#line 23 "calc.tab.c"
#define NUMBER 257
#define LETTER 258
#define ENDL 259
#define PLUS 260
#define MINUS 261
#define MUL 262
#define DIV 263
#define L_BRAC 264
#define R_BRAC 265
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    0,    1,    1,    2,    2,    2,    2,    2,
    2,    2,
};
short yylen[] = {                                         2,
    0,    3,    4,    1,    3,    3,    3,    3,    3,    3,
    1,    1,
};
short yydefred[] = {                                      1,
    0,   12,    0,    0,    0,    0,    0,   11,    0,    0,
    2,    0,    0,    0,    0,    0,    6,    3,    0,    0,
    9,   10,
};
short yydgoto[] = {                                       1,
    5,    6,
};
short yysindex[] = {                                      0,
 -251,    0,  -47, -223, -255, -224, -223,    0, -218, -241,
    0, -223, -223, -223, -223, -224,    0,    0, -212, -212,
    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0, -230,    0,    0, -254,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -210,    0,    0, -244, -237,
    0,    0,
};
short yygindex[] = {                                      0,
    0,   -4,
};
#define YYTABLESIZE 51
short yytable[] = {                                       9,
   10,    4,   16,   11,    4,    2,    3,   19,   20,   21,
   22,    7,    4,    7,    7,    7,    7,   18,    8,    0,
    7,    8,    8,    8,    0,   11,    0,    8,   11,   11,
   11,   11,   11,    2,    8,   12,   13,   14,   15,    0,
    4,   12,   13,   14,   15,    5,   17,    0,    5,   14,
   15,
};
short yycheck[] = {                                       4,
  256,  256,    7,  259,  259,  257,  258,   12,   13,   14,
   15,  256,  264,   61,  259,  260,  261,  259,  256,   -1,
  265,  259,  260,  261,   -1,  256,   -1,  265,  259,  260,
  261,  262,  263,  257,  258,  260,  261,  262,  263,   -1,
  264,  260,  261,  262,  263,  256,  265,   -1,  259,  262,
  263,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 265
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'='",0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"NUMBER","LETTER","ENDL",
"PLUS","MINUS","MUL","DIV","L_BRAC","R_BRAC",
};
char *yyrule[] = {
"$accept : calc",
"calc :",
"calc : calc stat ENDL",
"calc : calc stat error ENDL",
"stat : expr",
"stat : LETTER '=' expr",
"expr : L_BRAC expr R_BRAC",
"expr : expr PLUS expr",
"expr : expr MINUS expr",
"expr : expr MUL expr",
"expr : expr DIV expr",
"expr : LETTER",
"expr : NUMBER",
};
#endif
#ifndef YYSTYPE
typedef int YYSTYPE;
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#line 39 "d:\Projects\lex\testVcproj\testLex\calc.y"
void yyerror(const char * mess) { fprintf(stderr, "%s\n", mess); }
#line 139 "calc.tab.c"
#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 2:
#line 20 "d:\Projects\lex\testVcproj\testLex\calc.y"
{printf("result = %d\n", yyvsp[-1]);}
break;
case 3:
#line 21 "d:\Projects\lex\testVcproj\testLex\calc.y"
{yyerrok;}
break;
case 5:
#line 25 "d:\Projects\lex\testVcproj\testLex\calc.y"
{ printf("stat"); regs[yyvsp[-2]]=yyvsp[0]; yyval=yyvsp[0]; }
break;
case 6:
#line 29 "d:\Projects\lex\testVcproj\testLex\calc.y"
{yyval=yyvsp[-1]; printf("(%d);", yyval);}
break;
case 7:
#line 30 "d:\Projects\lex\testVcproj\testLex\calc.y"
{yyval=yyvsp[-2]+yyvsp[0]; printf("%d+%d=%d;",yyvsp[-2],yyvsp[0],yyval);}
break;
case 8:
#line 31 "d:\Projects\lex\testVcproj\testLex\calc.y"
{yyval=yyvsp[-2]-yyvsp[0]; printf("%d-%d=%d;",yyvsp[-2],yyvsp[0],yyval);}
break;
case 9:
#line 32 "d:\Projects\lex\testVcproj\testLex\calc.y"
{yyval=yyvsp[-2]*yyvsp[0]; printf("%d*%d=%d;",yyvsp[-2],yyvsp[0],yyval);}
break;
case 10:
#line 33 "d:\Projects\lex\testVcproj\testLex\calc.y"
{yyval=yyvsp[-2]/yyvsp[0]; printf("%d/%d=%d;",yyvsp[-2],yyvsp[0],yyval);}
break;
case 11:
#line 34 "d:\Projects\lex\testVcproj\testLex\calc.y"
{yyval=regs[yyvsp[0]]; printf("letter");}
break;
case 12:
#line 35 "d:\Projects\lex\testVcproj\testLex\calc.y"
{/*printf("NUMBER ");*/}
break;
#line 320 "calc.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
