#ifndef _ANALIZER_H_
#define _ANALIZER_H_ 1

#include <QDebug>
#include <QString>
#include <vector>

#define I_SEQ(seq) seq.begin(), seq.end()

//#define YYMAXDEPTH 200 //по умолчанию - 500
#define yylval  modulelval
#define yyerror moduleerror
#define yyin    modulein
#define yyparse moduleparse

#define YYSTYPE int
extern YYSTYPE yylval;

int yylex();
int yyparse();
void yyerror(const char * mess);
void yyerror(const QString& mess);
void yyerror(int, const QString& mess);

enum IdentType {
  itNone,                             // неопределенный тип
  itStruct, itEnum, itTsmiface,       // составные типы
  itFloat, itInt, itString, itChar,   // простые типы
  itCommand, itEvent,                 // команды и события
  itConst, itModule, itArg            // прочие элементы
};

inline bool isSimpleType(IdentType it) { return it==itFloat || it==itInt || it==itString || it==itChar; }
inline bool isComplexType(IdentType it) { return it==itStruct || it==itEnum || it==itTsmiface; }

struct CIdentInfo;
extern std::vector< QString > idents;   //!< таблица имен, на нее ссылается CIdentInfo::idName
extern std::vector< QString > strings;  //!< таблица строковых констант
extern std::vector< double >  floats;   //!< таблица констант типа itFloat
extern std::vector< CIdentInfo > syn_idents;  //!< таблица описания идентификаторов (фактически дерево разбора)

struct CIdentInfo {
  //общие свойства идентификаторов
  int idName;     //!< индекс имени в таблице имен (idents)
  IdentType type; //!< определенный в ходе разбора признак (тип) идентификатора
  int datatype;   //!< тип данных ( -1 - void, i - индекс в таблице идентификаторов, для идентификатора типа данных совпадает с индексом идентификатора)
  int scope;      //!< уровень данных
  int binding;    //!< привязка к родительскому типу (индекс предка в дереве разбора)
  int line;       //!< место первого включения идентификатора (для выдачи отладочных сообщений и сообщений об ошибках)
  // Специальные свойства идентификаторов
  uint vecDepth;  //!< глубина вложенности вектора (имеет смысл только для типизированного идентификатора)
  int sectType;   //!< секция формальных параметров - in, out, inout (имеет смысл только для параметров команды)
  bool isRaw;     //!< признак передачи параметра как "Raw Argument" (имеет смысл только для параметров команды или события)
  union {
    double val_double;  //!< значение константы (имеет смысл только для описания констант)
    int val_int;        //!< значение константы (имеет смысл только для описания констант и элементов перечисления)
  };
  // Поля для построения результата
  QString text;   //!< наименование поля в тексте результата для стандартных типов (isSimpleType)
  std::vector< CIdentInfo > loc_idents;   //!< поля записи (struct), параметры функции
public:
  CIdentInfo( int );
  const QString& name() const { return (isSimpleType(type)) ? text : idents[idName]; };
  bool operator==( int id ) const { return idName == id; }; /*uses in stl find function*/
  bool operator==( const CIdentInfo& ident ) const { return idName == ident.idName; }; /*uses in stl find function*/

#ifdef TSMDEBUG
  QString toString() const;
#endif
};

void startScope(); //!начало пространства имен (module, struct, enum или функция) - вызываем в def_ident
void stopScope();  //!окончание пространства имен - вызываем в обработчике module, struct и т.д.
int idByName( int , const std::vector<CIdentInfo>& );

int appendIdent(const char *);
int appendFloat(double);

#endif
