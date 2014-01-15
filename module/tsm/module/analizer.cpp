#include <vector>
#include <stack>
#include <algorithm>
#include <assert.h>
#include <stdio.h>

#include "analizer.h"
#include "generator.h"

using namespace std;

stack<int> bindingStack; //!< стек привязок ( предков текущего элемента в дереве разбора )
vector<QString> idents;   //!< таблица имен ( заполняется лексическим анализатором )
vector<QString> strings;  //!< таблица строковых констант ( заполняется лексическим анализатором )
vector<double>  floats;   //!< таблица констант типа itFloat
vector<CIdentInfo> syn_idents;  //!< дерево разбора ( заполняется синтаксическим анализатором )
vector<CIdentInfo> loc_idents;  //!< локальные идентификаторы, входящие в то или иное пространство имен ( заполняется синтаксическим анализатором )

extern int linenum; // файл module.l

CIdentInfo::CIdentInfo(int id)
  : idName(id), type(itNone),
    vecDepth(0), sectType(-1), isRaw(false) {
  line = linenum;
  scope = bindingStack.size(); // уровень вложенности идентификатора, см. idByName(...)
  binding = bindingStack.empty() ? -1 : bindingStack.top();
}

#ifdef TSMDEBUG

#include "generator_add.h"

QString CIdentInfo::toString() const {
  QString result;
  switch (type) {
  case itModule:
    result += QString("MODL %1").arg(name());
    break;
  case itStruct: case itEnum: case itFloat: case itInt: case itString: case itChar:
    result += QString("TYPE %1 (%2)").arg(name()).arg(datatype);
    break;
  default:
    result += QString("IDEN %1, TYPE ").arg(name());
    if (datatype>=0)
      result += QString("%1 (%2)").arg(syn_idents[datatype].name()).arg(datatype);
    else
      result += "void";
    if (vecDepth > 0)
      result += QString(", vector< %1 >").arg(vecDepth);
    break;
  }
  return getTabs(scope) + result;
}
#endif

//! Добавление нового имени в таблицу имен
int appendIdent (const char *name) {
  vector<QString>::iterator ident = find ( I_SEQ ( idents ), QString ( name ) );
  if ( ident == idents.end() )
    ident = idents.insert ( idents.end(), name );

  int id = ident - idents.begin();
  return id;
}

//! Добавление новой константы типа itFloat
int appendFloat(double value) {
  floats.push_back(value);
  return floats.size()-1;
}

//! Алгоритм определения доступности идентификатора (поиск ближайшего вхождения идентификатора в дереве разбора)
int idByName (int id, const vector<CIdentInfo>& vec = syn_idents) {
  int scope = bindingStack.size(); // уровень вложенности идентификатора
  int i = vec.size()-1;
  while (i >= 0) {
    if (vec[i].idName == id && vec[i].scope == scope)
      return i;
    if ( vec[i].scope > scope ) {
      assert ( i > vec[i].binding ); //должны обеспечить уменьшение i
      i = vec[i].binding;
    } else {
      scope = vec[i].scope;
      --i;
    }
  }
  return -1;
}

void startScope() {
  bindingStack.push ( syn_idents.size()-1 );
}

void stopScope() {
  bindingStack.pop();
}

void yyerror(const char *mess) {
  qCritical() << QString("%1: %2").arg(linenum).arg(mess);
}

void yyerror(const QString& mess) {
  qCritical() << linenum << ": " << mess;
}

void yyerror(int line, const QString& mess) {
  qCritical() << line << ": " << mess;
}
