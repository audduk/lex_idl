#include <QObject>

#include "tsm_test.h"

class CStartCatcher : public QObject {
    Q_OBJECT
public slots:
    void Start();
};

namespace SUMMATOR_client {

class testClient : public QObject {
    Q_OBJECT
public slots:
    void add_result(int);
    void sub_result(int);
/*signals:  //! нет необходимости в сигналах на стороне клиента (только слоты для получения результата)
    void add(numPair);
    void sub(int, int);
*/
};

}
