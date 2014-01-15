#ifndef _SRV_COLOR_H_
#define _SRV_COLOR_H_

#include <QList>
#include <tsm/tsminterface.h>

namespace colorPrimer_server {
  struct Object {
    int id_obj;
    Color col;
  };

  class collorSetter : public TSM::TsmInterface {
    Q_OBJECT
  public:
    static const QString e_colorChanged = "colorChanged";

    collorSetter(TSM::Commander*, const QString&);
    bool processCommand(const Command& cmd);
  public slots:
    void colorChanged(const Object & object);
    void setColors_result();
    void askColor_result(const Object & object);
  signals:
    void setColors(QList< Object > objects);
    void askColor(int id_obj);
  };

  class objectProcessor : public TSM::TsmInterface {
    Q_OBJECT
  public:
    static const QString e_objectChanged = "objectChanged";

    objectProcessor(TSM::Commander*, const QString&);
    bool processCommand(const Command& cmd);
  public slots:
    void objectChanged(const Object & object);
    void processObjects_result(const QList< Object > & objects);
  signals:
    void processObjects(QList< Object > objects);
  };

};

#endif // _SRV_COLOR_H_
