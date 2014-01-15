#include "analizer.h"
#include "generator_add.h"

// Реализация вспомогательных функций, для генерации результата

QString getTabs(int scope) {
  QString tmp;
  for (int i=0 ; i < scope; ++i)
    tmp += "  ";
  return tmp;
}

QString getType(const CIdentInfo& ident) {
  return syn_idents[ident.datatype].name();
}

QString getType(const CIdentInfo& ident, uint depth) {
  QString res = syn_idents[ident.datatype].name();
  for (uint i=0; i<depth; ++i)
    res = seqType+"< "+res+" >";
  return res;
}

QString getNameNum(const CIdentInfo& ident) {
  return ident.name() + ( ident.vecDepth>0? QString::number(ident.vecDepth) : "" );
}

QString typedIdent(const CIdentInfo& ident) {
  QString tmp = syn_idents[ident.datatype].name();
  for (uint i=0; i<ident.vecDepth; ++i)
    tmp = seqType+"< "+tmp+" >";
  return tmp + " " + ident.name();
}

QString typedIdentSlt(const CIdentInfo& ident) {
  const CIdentInfo& datatype = syn_idents[ident.datatype];
  QString tmp = datatype.name();
  for (uint i=0; i<ident.vecDepth; ++i)
    tmp = seqType+"< "+tmp+" >";
  if (datatype.type == itStruct || ident.vecDepth > 0)
    tmp = "const " + tmp + " &";
  return  tmp + " " + ident.name();
}

QString makeScope(const QString& ident, const QString& space, const QString& content, int scope) {
  return getTabs(scope) + space + " " + ident + " {\n" +  content + getTabs(scope) + "};\n";
}

QString getLocIndex(int vecDepth, const QString& vecIndex) {
  return (vecIndex=="" ? "i" : vecIndex) + (vecDepth>0 ? QString::number(vecDepth) : "");
}
