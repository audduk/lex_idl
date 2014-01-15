#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
#define yyparse moduleparse
#define yylex modulelex
#define yyerror moduleerror
#define yychar modulechar
#define yyval moduleval
#define yylval modulelval
#define yydebug moduledebug
#define yynerrs modulenerrs
#define yyerrflag moduleerrflag
#define yyss moduless
#define yyssp modulessp
#define yyvs modulevs
#define yyvsp modulevsp
#define yylhs modulelhs
#define yylen modulelen
#define yydefred moduledefred
#define yydgoto moduledgoto
#define yysindex modulesindex
#define yyrindex modulerindex
#define yygindex modulegindex
#define yytable moduletable
#define yycheck modulecheck
#define yyname modulename
#define yyrule modulerule
#define YYPREFIX "module"
#line 4 "module.y"

#include <algorithm>
#include "analizer.h"
#include "generator.h"

#line 42 "y.tab.c"
#define TOK_MODULE 257
#define TOK_ENUM 258
#define TOK_CONST 259
#define TOK_STRUCT 260
#define TOK_TSMIFACE 261
#define TOK_COMMANDS 262
#define TOK_EVENTS 263
#define TOK_INSECT 264
#define TOK_INOUTSECT 265
#define TOK_OUTSECT 266
#define TOK_SEQUENCE 267
#define TOK_IDENT 268
#define TOK_INT 269
#define TOK_FLOAT 270
#define TOK_STR 271
#define TOK_VOID 272
#define TOK_RAW 273
#define YYERRCODE 256
short modulelhs[] = {                                        -1,
    0,    0,    1,    2,    4,    4,    5,    5,    5,    5,
    6,    6,    6,    7,   11,   11,   12,    8,   13,   13,
   14,   14,    9,   15,   15,   15,   15,   16,   17,   18,
   18,   19,   19,   21,   20,   24,   23,   23,   23,   23,
   23,   23,   23,   23,   28,   25,   29,   26,   30,   27,
   22,   22,   22,   31,   31,   33,   10,   32,   32,    3,
};
short modulelen[] = {                                         2,
    1,    2,    1,    5,    1,    2,    1,    1,    1,    1,
    5,    5,    5,    6,    1,    2,    2,    6,    1,    3,
    1,    3,    6,    1,    1,    2,    2,    2,    2,    1,
    2,    1,    2,    6,    6,    0,    2,    1,    1,    1,
    2,    2,    2,    3,    0,    3,    0,    3,    0,    3,
    0,    1,    3,    1,    2,    0,    3,    1,    4,    1,
};
short moduledefred[] = {                                      0,
    0,    0,    1,    3,   60,    0,    2,    0,    0,   56,
    0,    0,    0,    5,    7,    8,    9,   10,    0,    0,
    0,    0,    0,    4,    6,    0,    0,    0,   58,    0,
   56,    0,    0,    0,   19,    0,    0,    0,    0,   57,
    0,    0,   15,    0,    0,    0,   24,   25,    0,    0,
    0,   11,   12,   13,    0,   17,    0,   16,    0,    0,
   30,    0,    0,   32,    0,   26,   27,   22,   18,   20,
   59,   14,    0,   31,    0,   33,   23,    0,    0,   45,
   47,   49,    0,    0,    0,    0,   40,   56,   54,    0,
    0,    0,    0,    0,    0,   37,    0,   42,   43,   55,
    0,    0,   46,   48,   50,   35,   44,   34,   53,
};
short moduledgoto[] = {                                       2,
    3,    4,    6,   13,   14,   15,   16,   17,   18,   89,
   42,   43,   34,   35,   46,   47,   48,   60,   63,   61,
   64,   90,   83,   84,   85,   86,   87,   92,   93,   94,
   91,   30,   21,
};
short modulesindex[] = {                                   -245,
 -242, -245,    0,    0,    0,  -87,    0, -236, -242,    0,
 -242, -242, -114,    0,    0,    0,    0,    0,  -79,  -16,
 -230,  -74,  -73,    0,    0, -220, -240,   -9,    0, -216,
    0, -222,   -8,  -42,    0,   -5,   -4,   -2, -230,    0,
   -1,  -69,    0, -213, -212, -124,    0,    0, -208,    3,
 -220,    0,    0,    0,    2,    0,    6,    0, -242, -213,
    0, -242, -212,    0,    8,    0,    0,    0,    0,    0,
    0,    0,   28,    0,   29,    0,    0, -231, -203,    0,
    0,    0,   30, -203, -223, -194,    0,    0,    0,   32,
   15, -203, -203, -203,   16,    0, -194,    0,    0,    0,
   17, -203,    0,    0,    0,    0,    0,    0,    0,
};
short modulerindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -38,    0,    0,    0,    0,    0,    0,    0,
    0, -221,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -122,
    0,    0, -120,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -41,  -31,    0,
    0,    0,    0,  -31,   36,   37,    0,    0,    0,    0,
  -27,  -37,  -33,  -31,    0,    0,   38,    0,    0,    0,
    0,  -37,    0,    0,    0,    0,    0,    0,    0,
};
short modulegindex[] = {                                      0,
   78,    0,    4,    0,   68,    0,    0,    0,    0,   -3,
    0,   40,    0,   33,    0,   42,   43,    0,    0,   26,
   27,  -75,    0,    0,    0,    7,  -65,    0,    0,    0,
    0,   52,    0,
};
#define YYTABLESIZE 239
short moduletable[] = {                                      36,
   65,   51,   28,   51,   29,   21,   20,   51,   96,   51,
   24,    1,   19,   52,   22,   23,  103,  104,  105,   98,
   99,    9,   10,   11,   12,    5,  109,   41,   36,   37,
   38,  107,   80,   81,   82,    8,   28,   29,   41,   44,
   45,   81,   82,   26,   27,   56,   56,   33,   31,   32,
   39,   40,   49,   52,   53,   57,   54,   56,   59,   62,
   68,   69,   73,   71,   72,   75,   77,   78,   79,   88,
   95,   82,  101,  102,  106,  108,   38,   39,   41,    7,
   25,   58,   50,   70,  100,   74,   21,   66,   67,   76,
   55,   97,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   44,   45,   28,
   28,   29,   29,    9,   10,   11,   12,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   36,   36,   51,   51,   56,
   56,   36,   51,   56,   56,   56,   56,   52,   52,
};
short modulecheck[] = {                                      41,
  125,   44,  125,   41,  125,   44,   10,   41,   84,   41,
  125,  257,    9,   41,   11,   12,   92,   93,   94,   85,
   86,  258,  259,  260,  261,  268,  102,   31,  269,  270,
  271,   97,  264,  265,  266,  123,  267,  268,   42,  262,
  263,  265,  266,  123,   61,  267,  268,  268,  123,  123,
   60,  268,   61,   59,   59,  125,   59,   59,  272,  272,
  269,   59,   59,   62,   59,   62,   59,   40,   40,  273,
   41,  266,   41,   59,   59,   59,   41,   41,   41,    2,
   13,   42,  125,   51,   88,   60,  125,   46,   46,   63,
   39,   85,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,  262,
  263,  262,  263,  258,  259,  260,  261,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  267,  268,  265,  266,  267,
  268,  273,  266,  267,  268,  267,  268,  265,  266,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 273
#if YYDEBUG
char *modulename[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,0,"';'","'<'","'='",
"'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"TOK_MODULE","TOK_ENUM","TOK_CONST","TOK_STRUCT","TOK_TSMIFACE",
"TOK_COMMANDS","TOK_EVENTS","TOK_INSECT","TOK_INOUTSECT","TOK_OUTSECT",
"TOK_SEQUENCE","TOK_IDENT","TOK_INT","TOK_FLOAT","TOK_STR","TOK_VOID","TOK_RAW",
};
char *modulerule[] = {
"$accept : result",
"result : statement",
"result : result statement",
"statement : module",
"module : TOK_MODULE def_ident '{' definition_list '}'",
"definition_list : definition",
"definition_list : definition_list definition",
"definition : const",
"definition : struct",
"definition : enum",
"definition : tsm_interface",
"const : TOK_CONST typed_ident '=' TOK_INT ';'",
"const : TOK_CONST typed_ident '=' TOK_FLOAT ';'",
"const : TOK_CONST typed_ident '=' TOK_STR ';'",
"struct : TOK_STRUCT def_ident '{' struct_arglist '}' ';'",
"struct_arglist : struct_arg",
"struct_arglist : struct_arglist struct_arg",
"struct_arg : typed_ident ';'",
"enum : TOK_ENUM def_ident '{' enum_list '}' ';'",
"enum_list : enum_value",
"enum_list : enum_list ',' enum_value",
"enum_value : TOK_IDENT",
"enum_value : TOK_IDENT '=' TOK_INT",
"tsm_interface : TOK_TSMIFACE def_ident '{' tsm_sections '}' ';'",
"tsm_sections : commands",
"tsm_sections : events",
"tsm_sections : tsm_sections commands",
"tsm_sections : tsm_sections events",
"commands : TOK_COMMANDS commandlist",
"events : TOK_EVENTS eventlist",
"commandlist : command",
"commandlist : commandlist command",
"eventlist : event",
"eventlist : eventlist event",
"event : TOK_VOID def_ident '(' arglist ')' ';'",
"command : TOK_VOID def_ident '(' command_sections ')' ';'",
"$$1 :",
"command_sections : $$1 arglist",
"command_sections : insection",
"command_sections : inoutsection",
"command_sections : outsection",
"command_sections : insection inoutsection",
"command_sections : insection outsection",
"command_sections : inoutsection outsection",
"command_sections : insection inoutsection outsection",
"$$2 :",
"insection : TOK_INSECT $$2 arglist",
"$$3 :",
"inoutsection : TOK_INOUTSECT $$3 arglist",
"$$4 :",
"outsection : TOK_OUTSECT $$4 arglist",
"arglist :",
"arglist : func_arg",
"arglist : func_arg ';' arglist",
"func_arg : typed_ident",
"func_arg : TOK_RAW typed_ident",
"$$5 :",
"typed_ident : $$5 type TOK_IDENT",
"type : TOK_IDENT",
"type : TOK_SEQUENCE '<' type '>'",
"def_ident : TOK_IDENT",
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
#line 224 "module.y"

#include <vector>
#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

using namespace std;

#define YYDEBUG 0

uint vecDepth;  //!< глубина вложенности вектора текущего типа (см. type_ident -> type -> type_ident)
int InOrOut = TOK_INOUTSECT; //!< признак текущей секции (см. command_sections)

static const char badTypeUse[] = "Bad type for constant value!";

//! создает структуру описания идентификатора типа (вводится новый тип)
int def_ident(int id)
{
    int currentId = idByName( id, syn_idents );
    if ( currentId > 0 ) {
        if (syn_idents[currentId].line == 0)
            yyerror( QString("Ident '%1' duplicates base type.").
                    arg(syn_idents[currentId].name()) );
        else
            yyerror( QString("Ident '%1' duplicated, first use in %2 line.").
                    arg(syn_idents[currentId].name()).
                    arg(syn_idents[currentId].line) );
        return -1;
    }
    syn_idents.push_back( CIdentInfo(id) );
    currentId = syn_idents.size()-1;

    CIdentInfo& ident = syn_idents[currentId];
    ident.datatype = currentId;
    return currentId;
}

//! определяет типизированный идентификатора (проверяется наличие заданного типа)
int typed_ident( int idType, int idIdent )
{
    int currentId = -1;
    int currentType = idByName( idType, syn_idents );
    if ( currentType >= 0 ) {
        syn_idents.push_back( CIdentInfo(idIdent) );
        currentId = syn_idents.size()-1;

        CIdentInfo& ident = syn_idents[currentId];
        ident.datatype = currentType;
        ident.vecDepth = vecDepth;  //расчитанная глубина вложенности вектора (см. type, раздел TOK_SEQUENCE)
    } else {
        yyerror( QString("Type '%1' undefined.").arg(idents[idType]) );
        //return -1;
        exit(-1);
    }
    return currentId;
}

//! Заполняет дополнительные параметры аргумента команды или события
int func_arg( int id )
{
    syn_idents[id].sectType = InOrOut;
    assert(syn_idents[id].type == itNone);
    syn_idents[id].type = itArg;
    return id;
}

//! заполняет значение целой константы
void setupIntConstant(CIdentInfo& ident, int value)
{   // целая константа может быть присвоена типу int или float
    if ( syn_idents[ident.datatype].type == itInt )
        ident.val_int = value;
    else if (syn_idents[ident.datatype].type == itFloat)
        ident.val_double = value;
    else
        yyerror( badTypeUse );
}

//! заполняет значение константы с плавающей точкой
void setupFloatConstant(CIdentInfo& ident, double value)
{   // константа может быть присвоена только типу float
    if (syn_idents[ident.datatype].type == itFloat)
        ident.val_double = value;
    else
        yyerror( badTypeUse );
}

//! предикат для определения типа идентификатора
struct notArg : public unary_function<CIdentInfo, bool> {
    bool operator()(const CIdentInfo& val) const { return val.type != itArg; } // "!=" тк используем в remove_copy_if
};
#line 380 "y.tab.c"
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
case 4:
#line 20 "module.y"
{
    syn_idents[yyvsp[-3]].type = itModule;
    stopScope();
    genModule(yyvsp[-3]);
    yyval = yyvsp[-3];
}
break;
case 5:
#line 30 "module.y"
{
    generate(yyvsp[0]);
}
break;
case 6:
#line 34 "module.y"
{
    generate(yyvsp[0]);
}
break;
case 11:
#line 46 "module.y"
{
    setupIntConstant(syn_idents[yyvsp[-3]], yyvsp[-1]);
    syn_idents[yyvsp[-3]].type = itConst;
    yyval = yyvsp[-3];
}
break;
case 12:
#line 52 "module.y"
{
    setupFloatConstant(syn_idents[yyvsp[-3]], floats[yyvsp[-1]]);
    syn_idents[yyvsp[-3]].type = itConst;
    yyval = yyvsp[-3];
}
break;
case 13:
#line 58 "module.y"
{
    yyerror( "String constant dosn't implement yet" );
    syn_idents[yyvsp[-3]].type = itConst;
    yyval = yyvsp[-3];
    /*exit(-1);*/
}
break;
case 14:
#line 67 "module.y"
{
    syn_idents[yyvsp[-4]].type = itStruct;
    remove_copy_if( syn_idents.begin()+yyvsp[-4]+1, syn_idents.end(), back_inserter(syn_idents[yyvsp[-4]].loc_idents), notArg() );
    /* < Примечание. При генерации, будем иметь дело и с полной последовательностью описателей (при генерации .h-файла) и с полями структуры (при генерации .cpp-файла)*/

    /*qDebug()<<syn_idents[syn_idents[$2].binding].name()<<"::"<<syn_idents[$2].name()<< " " <<syn_idents[$2].loc_idents.size() ;*/
    if (syn_idents[yyvsp[-4]].loc_idents.size()==0) yyerror("Empty struct found");
    assert(syn_idents[yyvsp[-4]].loc_idents.size()>0); /* пустые структуры запрещены*/

    stopScope();
    yyval = yyvsp[-4];
}
break;
case 17:
#line 85 "module.y"
{
    assert(syn_idents[yyvsp[-1]].type == itNone); /* тип уже должен быть определен - скорее всего ошибка разбора*/
    /*qDebug() << syn_idents[$1].name()<<syn_idents[$1].type;*/
    syn_idents[yyvsp[-1]].type = itArg;
}
break;
case 18:
#line 95 "module.y"
{
    syn_idents[yyvsp[-4]].type = itEnum;
    stopScope();
    yyval = yyvsp[-4];
}
break;
case 23:
#line 112 "module.y"
{
    syn_idents[yyvsp[-4]].type = itTsmiface;
    stopScope();
    yyval = yyvsp[-4];
}
break;
case 34:
#line 136 "module.y"
{
    syn_idents[yyvsp[-4]].type = itEvent;
    syn_idents[yyvsp[-4]].datatype = -1; /*void*/
    stopScope();
    yyval = yyvsp[-4];
}
break;
case 35:
#line 146 "module.y"
{
    syn_idents[yyvsp[-4]].type = itCommand;
    syn_idents[yyvsp[-4]].datatype = -1; /*void*/
    stopScope();
    yyval = yyvsp[-4];
}
break;
case 36:
#line 155 "module.y"
{ InOrOut = TOK_INOUTSECT; }
break;
case 45:
#line 166 "module.y"
{ InOrOut = TOK_INSECT; }
break;
case 47:
#line 172 "module.y"
{ InOrOut = TOK_INOUTSECT; }
break;
case 49:
#line 178 "module.y"
{ InOrOut = TOK_OUTSECT; }
break;
case 54:
#line 189 "module.y"
{
    func_arg(yyvsp[0]);
}
break;
case 55:
#line 193 "module.y"
{
    yyval = func_arg(yyvsp[0]);  /*наверх поднимается конкретный типизированный идентификатор*/
    syn_idents[yyvsp[0]].isRaw = true;    /* аргумент должен передаваться через AddRawArgument*/
}
break;
case 56:
#line 201 "module.y"
{   vecDepth = 0; }
break;
case 57:
#line 203 "module.y"
{   yyval = typed_ident(yyvsp[-1], yyvsp[0]); }
break;
case 59:
#line 209 "module.y"
{
    ++vecDepth;
    yyval = yyvsp[-1]; /*наверх поднимается конкретный идентификатор типа данных*/
}
break;
case 60:
#line 217 "module.y"
{
    yyval = def_ident(yyvsp[0]);
    startScope();
}
break;
#line 675 "y.tab.c"
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
