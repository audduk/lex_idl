#include <QObject>

#include "tsm_test.h"

namespace SUMMATOR_server{

class testServer : public QObject {
    Q_OBJECT
public slots:
    void add(numPair);  //! ������������� ������� ���������������� ������
    void sub(int, int); //! ������������� ������� ���������������� ������
signals:
    void add_result(int); //! ������������� ����� ���������������� ������
    void sub_result(int); //! ������������� ����� ���������������� ������
};

}
