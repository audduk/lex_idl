#include <QObject>

#include "tsm_test.h"

namespace SUMMATOR_server{

class testServer : public QObject {
    Q_OBJECT
public slots:
    void add(numPair);  //! соответствует сигналу сгенерированного класса
    void sub(int, int); //! соответствует сигналу сгенерированного класса
signals:
    void add_result(int); //! соответствует слоту сгенерированного класса
    void sub_result(int); //! соответствует слоту сгенерированного класса
};

}
