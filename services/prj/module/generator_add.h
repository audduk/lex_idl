#ifndef _GENERATOR_ADD_H_
#define _GENERATOR_ADD_H_

#include <QString>

typedef QString (*accIdent)(const CIdentInfo&, QString);

//! тип, используемый для генерации последовательности
const QString seqType  = "QList";
//! определение функкции
const QString funcDef  = "void %1%2(%3)";
//! содержимое слота (формирование команды и отсылка)
const QString slotImpl = " {\n"
    "  Command cmd;\n"
    "  cmd.SetCmd(\"%1\");\n"
    "%2"
    "  SendCommand(cmd);\n"
    "}\n\n";
//! обработка события - формирование сигнала с параметрами события (только клиент)
const QString processEvent =
    "  if (event == \"%1\") {\n"
    "%2"
    "    emit %1(%3);\n"
    "    return true;\n"
    "  }\n";
//! обработка команды - формирование сигнала с параметрами команды (только сервер)
const QString processCmd   =
    "  if (cmd.Cmd() == \"%1\") {\n"
    "%2"
    "    emit %1(%3);\n"
    "    return true;\n"
    "  }\n";
//! константа с наименованием события (для подписки на событие)
const QString eventConst = "static const QString e_%1 = \"%1\";\n";

//! Вспомогательные функции генерации файла

QString getTabs(int scope);                     //!< возвращает \a scope отступов
QString typedIdent(const CIdentInfo& ident);    //!< возвращает <тип> <имя параметра>
QString typedIdentSlt(const CIdentInfo& ident); //!< возвращает <тип> <имя параметра>, при этом для составных типов и последовательностей используется передача по константной ссылке (используется в параметрах слотов)
QString getNameNum(const CIdentInfo& ident);    //!< возвращает <имя параметра> с учетом воложенности вектора
//QString getType(const CIdentInfo& ident);       //!< возвращает <тип> параметра
QString getType(const CIdentInfo& ident, uint depth);  //!< возвращает <тип> параметра с учетом воложенности вектора ( \a depth )
QString makeScope(const QString&, const QString&, const QString&, int);  //!< формирует пространство имен (namespace, struct, class)
QString getLocIndex(int, const QString&);        //! возвращает имя индексной переменной (необходим при формировании циклов)

//! накопление информации (для обработки QStringList)
struct accList {
    QString operator()(const QString& init, const QString& value) const { return init + value + "\n"; }
};

#endif
