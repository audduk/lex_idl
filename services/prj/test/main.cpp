#include <QObject>
#include <QCoreApplication>
#include <QDebug>

#include <uniclient.h>
#include <tsm/commander.h>
#include "tsm_test.h"

#ifdef TSMSERVER
#include "testServer.h"
using namespace SUMMATOR_server;
#endif

#ifdef TSMCLIENT
#include "testClient.h"
using namespace SUMMATOR_client;

void CStartCatcher::Start()
{
}

#endif

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);

    qDebug() << "SELF NAME " << (*TSM::Client())->Disp_name() << " " <<  (*TSM::Client())->Self_name();

#ifdef TSMSERVER
    TSM::Client()->Init();
    summator * sum = new summator ( TSM::Client(), "" );

    testServer testS;
        // получение данных (параметров команды) от клиента (через локального диспетчера)
    testS.connect( sum, SIGNAL(add(numPair)), SLOT(add(numPair)) );
    testS.connect( sum, SIGNAL(sub(int,int)), SLOT(sub(int,int)) );
        // отправка результата выполнения команды клиенту (через локального диспетчера)
    sum->connect( &testS, SIGNAL(add_result(int)), SLOT(add_result(int)) );
    sum->connect( &testS, SIGNAL(sub_result(int)), SLOT(sub_result(int)) );
#endif

#ifdef TSMCLIENT
    CStartCatcher catcher;
    catcher.connect( TSM::Client(), SIGNAL(start()), SLOT(Start()));
    QString str("testServer");
    if ( (*TSM::Client())->Disp_name().size()>0 ) str = (*TSM::Client())->Disp_name()+"#"+str;
    qDebug() << "TRY TO CONNECT TO " << str;
    summator *sum = new summator( TSM::Client(), str );

    testClient testC; // получение ответа на команду
    testC.connect( sum, SIGNAL(add_result(int)), SLOT(add_result(int)) );
    testC.connect( sum, SIGNAL(sub_result(int)), SLOT(sub_result(int)) );

    // вызов команды (запрос данных у сервера)
    sum->sub(1,2);
    numPair num;
    num.first  = 1;
    num.second = 2;
    sum->add( num );
#endif

    app.exec();

    return 0;
}
