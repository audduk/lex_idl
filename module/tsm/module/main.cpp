#include <algorithm>
#include <QFile>
#include <QRegExp>

#include "analizer.h"
#include "generator.h"

//! Тип генерируемого класса (клиент или сервер) - используется в generator.cpp
TargetType tType = ttUndefined;

void preDefined();

inline void badUsage(const char *tsmName) {
  qCritical() << QString("tsm compiler usage:\n"
                         "%1 -t client|server [-p prefix] filename\n"
                         "%1 -h").arg(tsmName);
}

struct CPredefinedType {
  QString tsmName;
  QString hostName;
  IdentType type;
};

CPredefinedType predefined[] = {
  {"int",    "int",    itInt},
  {"long",   "long",   itInt},
  {"float",  "float",  itFloat},
  {"double", "double", itFloat},
  {"char",   "char",   itChar},
  {"date",   "QDate",   itString},
  {"time",   "QTime",   itString},
  {"string", "QString", itString}
};

int main(int argc, char* args[]) {
  extern FILE *yyin;  // файл module_lex.cpp
  extern QString resultH, resultCpp; // файл generator.cpp
  yyin = 0; //по умолчанию будет заполнено в функции yylex() в значение stdin

  const char *tsmName = args[0]; // имя запускаемого файла
  //обрабатываем входные параметры
  QString resname, filename, prefix;
  for ( int i=1; i<argc; ++i ) {
    if ( args[i][0] == '-' ) { // настроечный параметр
      switch (args[i][1]) {
      case 't': // установка типа формируемого выхода (клиент или сервер)
        ++i;
        if (strcmp(args[i], "client" )==0)
          tType = ttClient;
        else if (strcmp(args[i], "server" )==0)
          tType = ttServer;
        break;
      case 'r': // установка наименования результирующих файлов
        ++i;
        resname = args[i];
        break;
      case 'p':   // установка префикса выходного файла
        ++i;
        prefix = args[i];
        break;
      //case 's': // задаем имя файлов шаблонов
      // case 'x':
        // ...
        //break;
      case 'h': // запрос справки по использованию
      default:  // неизвестный параметр
        badUsage(tsmName);
        return 0;
      }
    } else { // последний параметр - имя файла для обработки
      filename = args[i];
#ifdef TSMDEBUG
      qDebug()<<"File to process "<<args[i];
      qDebug()<<"make "<< ( (tType==ttClient) ? "client" : "server" );
#endif
      break;
    }
  }
  if ( resname=="" ) {
    QRegExp rx("(\\w+)\\.\\w+");
    if ( rx.indexIn(filename)>=0 ) {
      resname = rx.cap(1);
    } else {
      resname = filename;
    }
  }
  if (prefix=="") prefix = "tsm_";
  QRegExp rx("^" + prefix + "\\w+");
  if ( !rx.exactMatch(resname) )  // если начинается не с $prefix
    resname = prefix + resname;
  qDebug() << "RES NAME = " << resname;

  if ( tType == ttUndefined || filename == "" ) {
    badUsage(tsmName);
    return -1;
  }

  yyin = fopen(filename.toLocal8Bit().data(), "r");
  if (yyin == 0) {
    qCritical() << "Unable to open file " << filename;
    return -1;
  }

  preDefined();
  int result = yyparse();

  if (yyin) fclose(yyin);

#ifdef TSMDEBUG
  //qDebug() << resultH << "\n";
  //qDebug() << resultCpp << "\n";
#endif

  QString hGuardian = "_" + resname.toUpper() + "_H_\n";

  QFile fH(resname+".h"), fCpp(resname+".cpp");

  fH.open(QIODevice::WriteOnly);
  QTextStream outH(&fH);
  outH << "#ifndef " << hGuardian;
  outH << "#define " << hGuardian << "\n";
  outH << "#include <QList>\n";
  outH << "#include <tsm/tsminterface.h>\n\n";
  //outH << "class Command;\n" ;    // -> см. файл <tsm/commander.h>
  //outH << "namespace TSM { class Commander; }\n\n" ;
  outH << resultH;
  outH << "\n#endif // " << hGuardian;

  fCpp.open(QIODevice::WriteOnly);
  QTextStream outCpp(&fCpp);
  outCpp << "#include <cmdparser.h>\n";
  outCpp << "#include <tsm/commander.h>\n\n";
  outCpp << "#include \"" + resname + ".h\"\n\n";
  outCpp << resultCpp << "\n";

  return result;
}

void applyPredef(const CPredefinedType& tp) {
  extern int def_ident(int); //см. module.y
  int i = def_ident( appendIdent(tp.tsmName.toAscii().data()) );
  syn_idents[i].type = tp.type;
  syn_idents[i].text = tp.hostName;
}

void preDefined() {
  extern int linenum; // файл module.l
  linenum = 0; // linenum==0 является признаком типов по умолчанию (для них не будет генерироваться результат)
  std::for_each(predefined, predefined+sizeof(predefined)/sizeof(predefined[0]), applyPredef);
  linenum = 1;
}
