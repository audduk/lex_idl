
#include <QtCore/QCoreApplication>
#include <QDebug>

extern "C" {
	int yydebug;
	int yyparse();
}


int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	yydebug = 1; 
	qDebug()<< yyparse();

	return a.exec();
}
