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
/*signals:  //! ��� ������������� � �������� �� ������� ������� (������ ����� ��� ��������� ����������)
    void add(numPair);
    void sub(int, int);
*/
};

}
