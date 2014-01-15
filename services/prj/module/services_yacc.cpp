#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
#define yyparse servicesparse
#define yylex serviceslex
#define yyerror serviceserror
#define yychar serviceschar
#define yyval servicesval
#define yylval serviceslval
#define yydebug servicesdebug
#define yynerrs servicesnerrs
#define yyerrflag serviceserrflag
#define yyss servicesss
#define yyssp servicesssp
#define yyvs servicesvs
#define yyvsp servicesvsp
#define yylhs serviceslhs
#define yylen serviceslen
#define yydefred servicesdefred
#define yydgoto servicesdgoto
#define yysindex servicessindex
#define yyrindex servicesrindex
#define yygindex servicesgindex
#define yytable servicestable
#define yycheck servicescheck
#define yyname servicesname
#define yyrule servicesrule
#define YYPREFIX "services"
#line 4 "services.y"

#include <algorithm>
#include "analizer.h"
#include "generator.h"

#line 42 "y.tab.c"
#define TOK_SERVICE 257
#define TOK_ENUM 258
#define TOK_CONST 259
#define TOK_STRUCT 260
#define TOK_SEQUENCE 261
#define TOK_IDENT 262
#define TOK_INT 263
#define TOK_FLOAT 264
#define TOK_STR 265
#define TOK_VOID 266
#define YYERRCODE 256
short serviceslhs[] = {                                        -1,
    0,    0,    1,    2,    4,    4,    5,    5,    5,    5,
    6,    6,    6,    7,   11,   11,   12,    8,   13,   13,
   14,   14,    9,   15,   15,   15,   16,   18,   10,   17,
   17,    3,
};
short serviceslen[] = {                                         2,
    1,    2,    1,    6,    1,    2,    1,    1,    1,    1,
    5,    5,    5,    6,    1,    2,    2,    6,    1,    3,
    1,    3,    6,    0,    1,    3,    1,    0,    3,    1,
    4,    1,
};
short servicesdefred[] = {                                      0,
    0,    0,    1,    3,   32,    0,    2,    0,    0,    0,
   28,    0,    0,    5,    7,    8,    9,   10,    0,    0,
    0,    0,    0,    4,    6,    0,    0,   30,    0,    0,
    0,   28,    0,    0,   29,    0,    0,   19,    0,    0,
    0,    0,    0,   15,   27,    0,    0,    0,    0,    0,
    0,   11,   12,   13,   17,    0,   16,    0,    0,   31,
   22,   18,   20,   14,   23,   26,
};
short servicesdgoto[] = {                                       2,
    3,    4,    6,   13,   14,   15,   16,   17,   18,   19,
   43,   44,   37,   38,   46,   47,   29,   20,
};
short servicessindex[] = {                                   -251,
 -243, -251,    0,    0,    0, -245,    0, -102, -250, -243,
    0, -243, -124,    0,    0,    0,    0,    0, -243, -246,
 -101,  -38,  -97,    0,    0,  -13,  -32,    0, -233, -232,
 -252,    0,    0, -246,    0,  -30,  -42,    0,  -27,  -26,
  -25,  -23,  -88,    0,    0,   -3,  -20,  -22, -222,  -17,
 -232,    0,    0,    0,    0,  -16,    0,  -15,    0,    0,
    0,    0,    0,    0,    0,    0,
};
short servicesrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0, -244,    0,
    0,    0, -244,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -41,    0,    0,  -40,    0,    0,    0,    0,
    0,    0, -244,    0,    0,    0,    4,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -41,    0,
    0,    0,    0,    0,    0,    0,
};
short servicesgindex[] = {                                      0,
   44,    0,   -5,    0,   34,    0,    0,    0,    0,   -8,
    0,    5,    0,   -2,   -9,    0,   18,    0,
};
#define YYTABLESIZE 221
short servicestable[] = {                                      24,
   24,   51,   22,   21,   21,    1,   23,   10,   11,   12,
   39,   40,   41,   26,   27,   28,   28,   28,    5,    8,
    9,   30,   31,   42,   45,   32,   33,   34,   35,   36,
   49,   52,   53,   54,   42,   55,   56,   58,   59,   60,
   61,   62,   64,   65,   25,    7,   25,   57,   63,   66,
   45,   48,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   50,    0,   21,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   10,   11,   12,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   28,
   28,
};
short servicescheck[] = {                                      41,
  125,   44,   11,   44,   10,  257,   12,  258,  259,  260,
  263,  264,  265,   19,  261,  262,  261,  262,  262,  265,
  123,  123,   61,   32,   33,  123,   40,   60,  262,  262,
   61,   59,   59,   59,   43,   59,  125,   41,   59,   62,
  263,   59,   59,   59,   41,    2,   13,   43,   51,   59,
   59,   34,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  125,   -1,  125,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  258,  259,  260,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  261,
  262,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 266
#if YYDEBUG
char *servicesname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,0,"';'","'<'","'='",
"'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"TOK_SERVICE","TOK_ENUM","TOK_CONST","TOK_STRUCT","TOK_SEQUENCE","TOK_IDENT",
"TOK_INT","TOK_FLOAT","TOK_STR","TOK_VOID",
};
char *servicesrule[] = {
"$accept : result",
"result : statement",
"result : result statement",
"statement : service",
"service : TOK_SERVICE def_ident TOK_STR '{' definition_list '}'",
"definition_list : definition",
"definition_list : definition_list definition",
"definition : const",
"definition : struct",
"definition : enum",
"definition : function",
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
"function : typed_ident def_ident '(' arglist ')' ';'",
"arglist :",
"arglist : func_arg",
"arglist : func_arg ';' arglist",
"func_arg : typed_ident",
"$$1 :",
"typed_ident : $$1 type TOK_IDENT",
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
#line 160 "services.y"

#include <vector>
#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

using namespace std;

#define YYDEBUG 0

uint vecDepth;  //!< глубина вложенности вектора текущего типа (см. type_ident -> type -> type_ident)
//int InOrOut = TOK_INOUTSECT; //!< признак текущей секции (см. command_sections)

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
    //syn_idents[id].sectType = InOrOut;
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
#line 322 "y.tab.c"
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
#line 20 "services.y"
{
    syn_idents[yyvsp[-4]].type = itService;
    stopScope();
    genService(yyvsp[-4], yyvsp[-3]);
    yyval = yyvsp[-4];
}
break;
case 5:
#line 30 "services.y"
{
    generate(yyvsp[0]);
}
break;
case 6:
#line 34 "services.y"
{
    generate(yyvsp[0]);
}
break;
case 11:
#line 46 "services.y"
{
    setupIntConstant(syn_idents[yyvsp[-3]], yyvsp[-1]);
    syn_idents[yyvsp[-3]].type = itConst;
    yyval = yyvsp[-3];
}
break;
case 12:
#line 52 "services.y"
{
    setupFloatConstant(syn_idents[yyvsp[-3]], floats[yyvsp[-1]]);
    syn_idents[yyvsp[-3]].type = itConst;
    yyval = yyvsp[-3];
}
break;
case 13:
#line 58 "services.y"
{
    yyerror( "String constant dosn't implement yet" );
    syn_idents[yyvsp[-3]].type = itConst;
    yyval = yyvsp[-3];
    /*exit(-1);*/
}
break;
case 14:
#line 69 "services.y"
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
#line 87 "services.y"
{
    assert(syn_idents[yyvsp[-1]].type == itNone); /* тип уже должен быть определен - скорее всего ошибка разбора*/
    /*qDebug() << syn_idents[$1].name()<<syn_idents[$1].type;*/
    syn_idents[yyvsp[-1]].type = itArg;
}
break;
case 18:
#line 97 "services.y"
{
    syn_idents[yyvsp[-4]].type = itEnum;
    stopScope();
    yyval = yyvsp[-4];
}
break;
case 23:
#line 115 "services.y"
{
    syn_idents[yyvsp[-4]].type = itFunction;
    syn_idents[yyvsp[-4]].datatype = yyvsp[-5];
    /*stopScope();*/
    yyval = yyvsp[-4];
}
break;
case 27:
#line 130 "services.y"
{
    func_arg(yyvsp[0]);
}
break;
case 28:
#line 137 "services.y"
{   vecDepth = 0; }
break;
case 29:
#line 139 "services.y"
{   yyval = typed_ident(yyvsp[-1], yyvsp[0]); }
break;
case 31:
#line 145 "services.y"
{
    ++vecDepth;
    yyval = yyvsp[-1]; /*наверх поднимается конкретный идентификатор типа данных*/
}
break;
case 32:
#line 153 "services.y"
{
    yyval = def_ident(yyvsp[0]);
    startScope();
}
break;
#line 577 "y.tab.c"
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
