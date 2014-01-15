#include <stack>
#include <algorithm>
#include <numeric>
#include <assert.h>

#include <QStringList>

#include "module_yacc.h"

#include "analizer.h"
#include "generator.h"
#include "generator_add.h"

using namespace std;

// TODO There is a problem in realization. We have to send result of a command to the process this command sent, but we do nothing
// TODO We can generate output during the parsing - at the end of the definition scope parsing

//! Структура является набором параметров функций модуля generator.cpp и предназначена для облегчения миграции параметров из одной функции в другую
struct LocalInfo {
  const CIdentInfo& ident;
  QString prefix;
  QString vecIndex;
  int scope;
  int vecDepth;
  LocalInfo(const CIdentInfo& id, const QString& pr, const QString& vI, int s, int vD)
    : ident(id), prefix(pr), vecIndex(vI), scope(s), vecDepth(vD) { }
};

typedef QString (*makeCppFunc)(const LocalInfo&);
typedef QString (*makeNameFunc)(const CIdentInfo&);

QString argToType(const LocalInfo&);
QString typeToArg(const LocalInfo&);

extern TargetType tType; //!< тип генерируемого класса (клиент или сервер) - заполняется в main.cpp

QStringList listCpp, listH; //!< накапливается результат генерации определений (definition)
//QStringList listConsts;     //! накапливаются константы с наименованиями команд и их аргументов
QString resultCpp, resultH; //!< накапливается результат генерации модулей (module)
stack<QString> structStack; //!< используется для передачи имени заполняемой структуры между функциями argToType и structToType

//! генерация результата для определения константы
QString genConst(const CIdentInfo& ident) {
  QString h = getTabs(ident.scope) + "const " + typedIdent(ident) + " = ";

  const CIdentInfo& datatype = syn_idents[ident.datatype];
  switch (datatype.type) {
  case itFloat:
    h += QString::number(ident.val_double);
    break;
  case itInt:
    h += QString::number(ident.val_int);
    break;
  default:
    yyerror(ident.line, QString("Constant of type '%1' is not implemented yet!").arg(datatype.name()));
    h = "";
    return "";
  }
  h += ";";
  listH << h;
  return h;
}

//! генерация результата для перечисления
QString genEnum(int id) {
  QString h = "enum " + syn_idents[id].name() + " {%1};";
  QString tmp;
  // Примечание - (syn_idents[j].binding==id) - только непосредственные потомки (1 уровень)
  for (uint j=id+1; j<syn_idents.size() && syn_idents[j].binding==id; ++j) {
    //для всех непосредственных потомков элемента (полей или других типов)
    const CIdentInfo& loc = syn_idents[j];
    if (!tmp.isEmpty())
      tmp += ", ";
    tmp += loc.name();
    if (loc.val_int >= 0)
      tmp += " = " + QString::number(loc.val_int);
  }
  return h.arg(tmp);
}

//! генерация результата для определения структуры
QString genStruct(int id) {
  QString h = "";
  const CIdentInfo& ident = syn_idents[id];
  // Примечание - (syn_idents[j].binding==id) - только непосредственные потомки (1 уровень)
  for (uint j=id+1; j<syn_idents.size() && syn_idents[j].binding==id; ++j) {
    //для всех непосредственных потомков элемента (полей или других типов)
    const CIdentInfo& loc = syn_idents[j];
    if ( loc.type == itArg ) // здесь itArg - полу структуры
      h += getTabs(loc.scope) + typedIdent(loc) + ";\n";
    else {
      generate(j);
      h += loc.text + "\n";
#ifdef TSMDEBUG
      qDebug() << loc.line << ": Only fields are implemented as structure fields";
#endif
    }
  }
  h = makeScope(ident.name(), "struct", h, ident.scope);
  listH << h;
  return h;
}

//! тип параметра для отбора (все, только входящие, только исходящие)
enum ArgumentType { atAll, atIn, atOut };

//! отбор передаваемого параметра по типу (для определения места где этот параметр используется)
bool checkAT(const CIdentInfo& loc, ArgumentType at) {
  return at ==atAll || (at == atIn && (loc.sectType == TOK_INSECT  || loc.sectType == TOK_INOUTSECT))
      || (at == atOut && (loc.sectType == TOK_OUTSECT || loc.sectType == TOK_INOUTSECT));
}

//! генерация результата для определения функции (команды или события)
QString genHFuncArgs(int id, ArgumentType at, makeNameFunc func) {
  QString res;
  for (uint j=id+1; j<syn_idents.size() && syn_idents[id].scope<syn_idents[j].scope; ++j) {
    //для всех непосредственных потомков элемента (аргументы команды)
    assert(syn_idents[j].binding == id); //для функций допустим только один уровень вложенности аттрибутов
    const CIdentInfo& loc = syn_idents[j];
    if (checkAT(loc, at)) {
      if (res.size() > 0)
        res += ", ";
      res += func(loc);
    }
  }
  return res;
}

//! генерация результата для реализации функции (команды или события)
QString genCppFuncArgs(int id, ArgumentType at, makeCppFunc func) {
  QString res;
  for (uint j=id+1; j<syn_idents.size() && syn_idents[id].scope<syn_idents[j].scope; ++j) {
    //для всех непосредственных потомков элемента (аргументы команды)
    const CIdentInfo& loc = syn_idents[j];
    if (checkAT(loc, at))
      res += func(LocalInfo(loc, "arg", "", 2, loc.vecDepth));
  }
  return res;
}

//! генерация результата для определения структуры
void genTsmiface(int id) {
  const CIdentInfo& ident = syn_idents[id];

  QString sltH, sigH, evConst;
  QString sltC, sigC, sigE; //для слотов создаем содержимое методов, для сигналов - содержимое методов processCommand и processEvent
  for (uint j=id+1; j<syn_idents.size() && ident.scope<syn_idents[j].scope; ++j) {
    //для всех непосредственных потомков элемента  - для комманды или события
    const CIdentInfo& loc = syn_idents[j];
    const QString  locTabs = getTabs(loc.scope);
    const QString& locName = loc.name();
    if (loc.type == itEvent) {
      evConst += locTabs + eventConst.arg(locName);
      if ( tType == ttServer ) { // на сервере событие генерируется слотом
        sltH += locTabs + funcDef.arg("").arg(locName).arg( genHFuncArgs(j, atAll, typedIdentSlt) ) + ";\n";
        QString tCpp = funcDef.arg(ident.name()+"::").arg(locName).arg( genHFuncArgs(j, atAll, typedIdent) ) + slotImpl;
        sltC += tCpp.arg(locName).arg( genCppFuncArgs(j, atAll, typeToArg) );
      } else { // на клиенте генерируем метод processCommand для расшифровки аргументов и вызова сигнала
        sigH += locTabs + funcDef.arg("").arg(locName).arg( genHFuncArgs(j, atAll, typedIdent) ) + ";\n";
        sigE += processEvent.arg(locName).
            arg( genCppFuncArgs(j, atAll, argToType) ).arg( genHFuncArgs(j, atAll, getNameNum) );
      }
    } else if (loc.type == itCommand) {
      QString tIn  = "void %1" + locName + "(%2)";
      QString tOut = "void %1" + locName + "_result(%2)";

      if ( tType == ttServer ) { //на сервере генерируем ->
        // сигнал о получении команды (со входными параметрами) и слот для выдачи результата (с выходными параметрами)
        sigH += locTabs + tIn. arg("").arg(genHFuncArgs(j, atIn, typedIdent)) + ";\n";
        sltH += locTabs + tOut.arg("").arg(genHFuncArgs(j, atOut, typedIdentSlt)) + ";\n";
        // содержимое processCommand для расшифровки параметров полученной команды и вызова сигнала
        sigC += processCmd.arg(locName).
            arg( genCppFuncArgs(j, atIn, argToType) ).arg( genHFuncArgs(j, atIn, getNameNum) );
        // содержимое слота, для отсылки результата команды
        QString tCpp = tOut.arg(ident.name()+"::").arg(genHFuncArgs(j, atOut, typedIdentSlt)) + slotImpl;
        sltC += tCpp.arg( locName + "_result" ).arg( genCppFuncArgs(j, atOut, typeToArg) );
      } else { // на клиенте генерируем ->
        // слот для выдачи команды (со входными параметрами) и сигнал о получении результата (с выходными параметрами)
        sltH += locTabs + tIn.arg("").arg(genHFuncArgs(j, atIn, typedIdentSlt)) + ";\n";
        sigH += locTabs + tOut. arg("").arg(genHFuncArgs(j, atOut, typedIdent)) + ";\n";
        // содержимое processCommand для расшифровки результата выполнения команды и вызова сигнала
        sigC += processCmd.arg( locName + "_result" ).
            arg( genCppFuncArgs(j, atOut, argToType) ).arg( genHFuncArgs(j, atOut, getNameNum) );
        // содержимое слота для упаковки параметров команды
        QString tCpp = tIn.arg(ident.name()+"::").arg( genHFuncArgs(j, atIn, typedIdentSlt) ) + slotImpl;
        sltC += tCpp.arg(locName).arg( genCppFuncArgs(j, atIn, typeToArg) );
      }
    } else if (loc.type == itArg) {
      // обнаружен аргумент функции - пропускаем
    } else {
      yyerror(loc.line, QString("Unexpected element '%1' type").arg(loc.name()));
    }
    assert( structStack.empty() ); // после завершения обработки очередного параметра стек должен быть пустым
  }
  const QString tabs = getTabs(ident.scope);
  const QString tabs1 = getTabs(ident.scope+1);

  QString content;
  if (sltH.size()>0 || sigH.size()>0)
    content += tabs1 + "Q_OBJECT\n";
  content += tabs + "public:\n";
  if (evConst.size()>0) //добавляем константы с наименованиями событий, необходимы для подписки на события
    content += evConst + "\n";
  // конструктор
  content += tabs1 + ident.name() + "(TSM::Commander*, const QString&);\n";
  // обработка входящих команд (результатов команд)
  if (sigC.size()>0)
    content += tabs1 + "bool processCommand(const Command& cmd);\n";
  // обработка входящих событий
  if (sigE.size()>0)
    content += tabs1 + "bool processEvent(const QString& event, const Argument& arg);\n";
  if (sltH.size()>0)
    content += tabs + "public slots:\n" + sltH;
  if (sigH.size()>0)
    content += tabs + "signals:\n" + sigH;
  QString h = makeScope(ident.name()+" : public TSM::TsmInterface", "class", content, ident.scope);

  QString cpp = QString("\n%1::%1(TSM::Commander* cl, const QString& rec) : TSM::TsmInterface(cl, rec) { }\n\n").arg(ident.name());
  if ( sigC.size()>0 )
    cpp += QString("bool %1::processCommand(const Command& cmd) {\n%2\treturn false;\n}\n").arg(ident.name()).arg(sigC);
  if ( sigE.size()>0)
    cpp += QString("bool %1::processEvent(const QString& event, const Argument& cmd) {\n%2\treturn false;\n}\n").arg(ident.name()).arg(sigE);
  if ( sltC.size()>0 ) cpp += "\n" + sltC;

  listH << h;
  listCpp << cpp;
}

//! генерация результата для определения (definition)
QString generate(int id) {
  QString tmp;
  const CIdentInfo& ident = syn_idents[id];
  switch (ident.type) {
  case itConst:
    tmp = genConst(ident); break;
  case itStruct:
    tmp = genStruct(id); break;
  case itEnum:
    tmp = genEnum(id); break;
  case itTsmiface:
    genTsmiface(id); break;
  default:
#ifdef TSMDEBUG
    qDebug() << ident.line << ": Ident '" << ident.name() << "' cannot be generated yet";
#endif
    return "";
  }
  return tmp;
}

//! генерация результата для модуля (module)
void genModule(int id) {
  QString h   = accumulate( I_SEQ(listH),   QString(""), accList() );
  QString cpp = accumulate( I_SEQ(listCpp), QString(""), accList() );
  listH.clear();
  listCpp.clear();

  const CIdentInfo& ident = syn_idents[id];
  if (cpp.size() > 0)
    resultCpp += makeScope(ident.name() + (tType==ttClient ? "_client" : "_server"), "namespace", cpp, 0);
  if (h.size() > 0)
    resultH += makeScope(ident.name() + (tType==ttClient ? "_client" : "_server"), "namespace", h, ident.scope);
}

//! преобразование аргумента команды в содержимое структуры - расшифровка аргумента команды
QString structToArg(const LocalInfo& info) {
  QString res;
  const CIdentInfo& datatype = syn_idents[info.ident.datatype];
  assert(datatype.type == itStruct);
  structStack.push(info.ident.name());
  for (uint i=0; i<datatype.loc_idents.size(); ++i) {
    const CIdentInfo& loc = datatype.loc_idents[i];
    res += argToType( LocalInfo(loc, info.prefix, info.vecIndex, info.scope, loc.vecDepth) );
  }
  structStack.pop();
  return res;
}

//! преобразование аргумента команды в содержимое типа (расшифровка аргумента команды, для генерации функций processCommand и processEvent)
QString argToType(const LocalInfo& info) {
  const CIdentInfo& datatype = syn_idents[info.ident.datatype];
  const QString locArgName = info.prefix + "_" + info.ident.name();
  const QString tabs = getTabs(info.scope);

  QString result = (tabs + "const Argument & %1 = ").arg(locArgName);
  // получение аргумента для очередного параметра (отличается для простых параметров)
  if ( info.vecIndex == "" ) {
    QString pref = info.prefix=="arg" ? "cmd" : info.prefix; // первый уровень префикса  - загрузка аргумента из команды
    result = (result + "%1.GetArgument(\"%2\");\n").arg(pref).arg(info.ident.name());
  } else
    result = (result + "%1[%2];\n").arg(info.prefix).arg(info.vecIndex);

  if (info.vecDepth == 0) {
    result += tabs;
    // блокируем заполнение структуры для вложенных в структуру векторов
    result += (structStack.empty() || structStack.top()=="") ? getType(info.ident, info.vecDepth) + " " : structStack.top() + ".";
    result += info.ident.name();

    if ( isSimpleType(datatype.type) ) {
      result += QString(" = %1.").arg(locArgName);
      if (datatype.type == itInt)    result += "toVariant().toInt();\n";
      if (datatype.type == itFloat)  result += "toVariant().toDouble();\n";
      if (datatype.type == itString) result += "toString();\n";
    }
    if (datatype.type == itEnum)
      result += QString(" = static_cast<%1>(%2.toInt());\n").arg(datatype.name()).arg(locArgName);
    if (datatype.type == itStruct) {
      result += ";\n";
      LocalInfo structInfo = info;
      structInfo.prefix = locArgName;
      structInfo.vecIndex = "";
      result += structToArg( structInfo );
      //result += "\n";
    }
    if (datatype.type == itTsmiface)
      yyerror(info.ident.line, "Unable to send interface parameter yet!");
  } else { // ident.vecDepth > 0
    const QString locIdentName = info.ident.name() + QString::number(info.vecDepth);
    const QString locNextName  = info.ident.name() + ( info.vecDepth>1 ? QString::number(info.vecDepth-1) : "");
    const QString locArgList   = locArgName + QString::number(info.vecDepth);
    const QString locNextList  = locArgList+"_" + locNextName;
    const QString locIndex     = getLocIndex(info.vecDepth, info.vecIndex);

    structStack.push(""); // блокируем заполнение структуры для вложенных в структуру векторов

    result += (tabs + getType(info.ident, info.vecDepth) + " " + locIdentName + ";\n");
    result += (tabs + "QList< Argument > %1 = %2.GetArgs(\"\");\n").arg(locArgList).arg(locArgName);
    //result += (tabs + "%1.reserve(%2.size());\n").arg(locIdentName).arg(locArgList);
    result += (tabs + "for (int %1=0; %1<%2.size(); ++%1) {\n").arg(locIndex).arg(locArgList);
    result += argToType( LocalInfo(info.ident, locArgList, locIndex, info.scope+1, info.vecDepth-1) );
    result += (getTabs(info.scope+1) + "%1.push_back(%2);\n").arg(locIdentName).arg(locNextName);
    result += (tabs + "}\n");

    structStack.pop();
    if ( !structStack.empty() && structStack.top()!="" )
      result += (tabs + "%1.%2 = %3;\n").arg(structStack.top()).arg(info.ident.name()).arg(locIdentName);
  }
  //qDebug() << result;
  return result;
}

//! преобразование аргумента команды в содержимое структуры - расшифровка аргумента команды
QString argToStruct( const LocalInfo& info ) {
  QString res;
  const CIdentInfo& datatype = syn_idents[info.ident.datatype];
  assert(datatype.type == itStruct);
  structStack.push(info.ident.name());
  for (uint i=0; i<datatype.loc_idents.size(); ++i) {
    const CIdentInfo& loc = datatype.loc_idents[i];
    res += typeToArg( LocalInfo(loc, info.prefix, info.vecIndex, info.scope, loc.vecDepth) );
  }
  structStack.pop();
  return res;
}

//! преобразование содержимого типа в аргумент команды
QString typeToArg( const LocalInfo& info) {
  const CIdentInfo& datatype = syn_idents[info.ident.datatype];
  const QString& name = info.ident.name();
  const QString tabs = getTabs(info.scope);
  QString locArgName = "arg_"+name; // см. структуры и последовательности
  if ( info.vecDepth>0 ) locArgName += QString::number(info.vecDepth);
  const QString pref = info.prefix=="arg" ? "cmd" : info.prefix; // первый уровень префикса  - загрузка аргумента из команды

  QString result;
  if (info.vecDepth == 0) {
    // расчет локального имени (различается для простых имен, полей структур и элементов векторов )
    const bool isStruct = !structStack.empty() && structStack.top()!="";
    QString locIdentName = (isStruct) ? structStack.top() : name;
    if (info.vecIndex != "") locIdentName += QString("[%1]").arg(info.vecIndex);
    if (isStruct)            locIdentName += "." + name;

    if ( isSimpleType(datatype.type) )
      result += (tabs + "%1.AddVariantArgument(\"%2\", QVariant(%3));\n").
          arg(pref).arg(name).arg(locIdentName);
    if ( datatype.type == itEnum )
      result += (tabs + "%1.AddVariantArgument(\"%2\", QVariant(static_cast<int>(%3)));\n").
          arg(pref).arg(name).arg(locIdentName);
    if ( datatype.type == itStruct ) {
      // при добавление структуры или последовательности значение содержится во вложенных аргументах
      result += (tabs + "Argument & %1 = %2.AddArgument(\"%3\",\"\");\n").
          arg(locArgName).arg(pref).arg(name);
      LocalInfo structInfo = info;
      structInfo.prefix = locArgName;
      //++structInfo.scope;
      result += argToStruct( structInfo );
    }
  } else { // info.vecDepth > 0
//    const QString locIdentName = info.ident.name() + QString::number(info.vecDepth);
//    const QString locNextName  = info.ident.name() + ( info.vecDepth>1 ? QString::number(info.vecDepth-1) : "");
//    const QString locArgList = locArgName + QString::number(info.vecDepth);
//    const QString locNextList = locArgList+"_" + locNextName;
    const QString locIndex = getLocIndex( info.vecDepth, info.vecIndex );

    structStack.push(""); // блокируем заполнение структуры для вложенных в структуру векторов

    // при добавление структуры или последовательности значение содержится во вложенных аргументах
    result += (tabs + "Argument & %1 = %2.AddArgument(\"%3\", \"\");\n").
        arg(locArgName).arg(pref).arg(name);
    result += (tabs + "for ( int %1=0; %1<%2.size(); ++%1 ) {\n").arg(locIndex).arg(name);
    result += typeToArg( LocalInfo(info.ident, locArgName, locIndex, info.scope+1, info.vecDepth-1) );
    //result += (getTabs(info.scope+1) + "%1.push_back(%2);\n").arg(locIdentName).arg(locNextName);
    result += (tabs + "};\n");

    /*
    result += (getTabs(info.scope+1) + "%1.push_back(%2);\n").arg(locIdentName).arg(locNextName);
    result += tabs + "}\n";*/

    structStack.pop();
    /*if ( !structStack.empty() && structStack.top()!="" )
        result += (tabs + "%1.%2 = %3;\n").arg(structStack.top()).arg(info.ident.name()).arg(locIdentName);*/
  }
  return result;
}
