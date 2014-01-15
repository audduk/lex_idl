%token TOK_SERVICE TOK_ENUM TOK_CONST TOK_STRUCT TOK_SEQUENCE TOK_IDENT TOK_INT TOK_FLOAT TOK_STR TOK_VOID

%{

#include <algorithm>
#include "analizer.h"
#include "generator.h"

%}

%%

result: statement | result statement
;

statement: service
;

service: TOK_SERVICE def_ident TOK_STR '{' definition_list '}'
{
    syn_idents[$2].type = itService;
    stopScope();
    genService($2, $3);
    $$ = $2;
}
;

definition_list:
definition
{
    generate($1);
}
| definition_list definition
{
    generate($2);
}
;

definition: const | struct | enum | function
;

/*Определение константы*/

const:
TOK_CONST typed_ident '=' TOK_INT ';'
{
    setupIntConstant(syn_idents[$2], $4);
    syn_idents[$2].type = itConst;
    $$ = $2;
}
| TOK_CONST typed_ident '=' TOK_FLOAT ';'
{
    setupFloatConstant(syn_idents[$2], floats[$4]);
    syn_idents[$2].type = itConst;
    $$ = $2;
}
| TOK_CONST typed_ident '=' TOK_STR ';'
{
    yyerror( "String constant dosn't implement yet" );
    syn_idents[$2].type = itConst;
    $$ = $2;
    //exit(-1);
}
;

/*Определение структуры (составного типа данных)*/

struct: TOK_STRUCT def_ident '{' struct_arglist '}' ';'
{
    syn_idents[$2].type = itStruct;
    remove_copy_if( syn_idents.begin()+$2+1, syn_idents.end(), back_inserter(syn_idents[$2].loc_idents), notArg() );
    // < Примечание. При генерации, будем иметь дело и с полной последовательностью описателей (при генерации .h-файла) и с полями структуры (при генерации .cpp-файла)

    //qDebug()<<syn_idents[syn_idents[$2].binding].name()<<"::"<<syn_idents[$2].name()<< " " <<syn_idents[$2].loc_idents.size() ;
    if (syn_idents[$2].loc_idents.size()==0) yyerror("Empty struct found");
    assert(syn_idents[$2].loc_idents.size()>0); // пустые структуры запрещены

    stopScope();
    $$ = $2;
}
;

struct_arglist: struct_arg | struct_arglist struct_arg
;

struct_arg: typed_ident ';'
{
    assert(syn_idents[$1].type == itNone); // тип уже должен быть определен - скорее всего ошибка разбора
    //qDebug() << syn_idents[$1].name()<<syn_idents[$1].type;
    syn_idents[$1].type = itArg;
}
;

/*Определение перечисления*/

enum: TOK_ENUM def_ident '{' enum_list '}' ';'
{
    syn_idents[$2].type = itEnum;
    stopScope();
    $$ = $2;
}
;

enum_list: enum_value | enum_list ',' enum_value
;

/* особенность идентификатор enum_value принадлежит перечислению (binding), но доступен в вышестоящем пространстве имен (scope)*/
enum_value: TOK_IDENT | TOK_IDENT '=' TOK_INT
;

/*Определение функции*/

function:
typed_ident def_ident '(' arglist ')' ';'
{
    syn_idents[$2].type = itFunction;
    syn_idents[$2].datatype = $1;
    //stopScope();
    $$ = $2;
}
;

arglist:
    /* список может быть пустой (здесь это важно!!!)*/
| func_arg | func_arg ';' arglist
;

func_arg:
typed_ident
{
    func_arg($1);
}
;

/** typed_ident вводится для унификации процедуры обработки типизированных идентификаторов */
typed_ident:
    {   vecDepth = 0; } //инициируем тип, не являющийся массивом - накопление глубины массива в type
type TOK_IDENT
    {   $$ = typed_ident($2, $3); }
;

type:
  TOK_IDENT
| TOK_SEQUENCE '<' type '>'
{
    ++vecDepth;
    $$ = $3; //наверх поднимается конкретный идентификатор типа данных
}
;

/** def_ident вводится для унификации процедуры обработки заголовков пространства имен */
def_ident: TOK_IDENT
{
    $$ = def_ident($1);
    startScope();
}
;

%%

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
