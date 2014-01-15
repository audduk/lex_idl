#ifndef _GENERATOR_H_
#define _GENERATOR_H_

#include <QString>

//! тип генерируемого класса (клиент или сервер)
enum TargetType { ttUndefined, ttClient, ttServer };

QString generate(int);
void genModule(int);

#endif
