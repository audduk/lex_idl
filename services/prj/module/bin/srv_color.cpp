#include <cmdparser.h>
#include <tsm/commander.h>

#include "srv_color.h"

namespace colorPrimer_server {

collorSetter::collorSetter(TSM::Commander* cl, const QString& rec) : TSM::TsmInterface(cl, rec) { }

bool collorSetter::processCommand(const Command& cmd) {
  if (cmd.Cmd() == "setColors") {
    const Argument & arg_objects = cmd.GetArgument("objects");
    QList< Object > objects1;
    QList< Argument > arg_objects1 = arg_objects.GetArgs("");
    for (int i1=0; i1<arg_objects1.size(); ++i1) {
      const Argument & arg_objects1_objects = arg_objects1[i1];
      Object objects;
      const Argument & arg_objects1_objects_id_obj = arg_objects1_objects.GetArgument("id_obj");
      objects.id_obj = arg_objects1_objects_id_obj.toVariant().toInt();
      const Argument & arg_objects1_objects_col = arg_objects1_objects.GetArgument("col");
      objects.col = static_cast<Color>(arg_objects1_objects_col.toInt());
      objects1.push_back(objects);
    }
    emit setColors(objects1);
    return true;
  }
  if (cmd.Cmd() == "askColor") {
    const Argument & arg_id_obj = cmd.GetArgument("id_obj");
    int id_obj = arg_id_obj.toVariant().toInt();
    emit askColor(id_obj);
    return true;
  }
	return false;
}

void collorSetter::colorChanged(Object object) {
  Command cmd;
  cmd.SetCmd("colorChanged");
    Argument & arg_object = cmd.AddArgument("object","");
    arg_object.AddVariantArgument("id_obj", QVariant(object.id_obj));
    arg_object.AddVariantArgument("col", QVariant(static_cast<int>(object.col)));
  SendCommand(cmd);
}

void collorSetter::setColors_result() {
  Command cmd;
  cmd.SetCmd("setColors_result");
  SendCommand(cmd);
}

void collorSetter::askColor_result(const Object & object) {
  Command cmd;
  cmd.SetCmd("askColor_result");
    Argument & arg_object = cmd.AddArgument("object","");
    arg_object.AddVariantArgument("id_obj", QVariant(object.id_obj));
    arg_object.AddVariantArgument("col", QVariant(static_cast<int>(object.col)));
  SendCommand(cmd);
}



objectProcessor::objectProcessor(TSM::Commander* cl, const QString& rec) : TSM::TsmInterface(cl, rec) { }

bool objectProcessor::processCommand(const Command& cmd) {
  if (cmd.Cmd() == "processObjects") {
    const Argument & arg_objects = cmd.GetArgument("objects");
    QList< Object > objects1;
    QList< Argument > arg_objects1 = arg_objects.GetArgs("");
    for (int i1=0; i1<arg_objects1.size(); ++i1) {
      const Argument & arg_objects1_objects = arg_objects1[i1];
      Object objects;
      const Argument & arg_objects1_objects_id_obj = arg_objects1_objects.GetArgument("id_obj");
      objects.id_obj = arg_objects1_objects_id_obj.toVariant().toInt();
      const Argument & arg_objects1_objects_col = arg_objects1_objects.GetArgument("col");
      objects.col = static_cast<Color>(arg_objects1_objects_col.toInt());
      objects1.push_back(objects);
    }
    emit processObjects(objects1);
    return true;
  }
	return false;
}

void objectProcessor::objectChanged(Object object) {
  Command cmd;
  cmd.SetCmd("objectChanged");
    Argument & arg_object = cmd.AddArgument("object","");
    arg_object.AddVariantArgument("id_obj", QVariant(object.id_obj));
    arg_object.AddVariantArgument("col", QVariant(static_cast<int>(object.col)));
  SendCommand(cmd);
}

void objectProcessor::processObjects_result(const QList< Object > & objects) {
  Command cmd;
  cmd.SetCmd("processObjects_result");
    Argument & arg_objects1 = cmd.AddArgument("objects", "");
    for ( int i1=0; i1<objects.size(); ++i1 ) {
      Argument & arg_objects = arg_objects1.AddArgument("objects","");
      arg_objects.AddVariantArgument("id_obj", QVariant(objects[i1].id_obj));
      arg_objects.AddVariantArgument("col", QVariant(static_cast<int>(objects[i1].col)));
    };
  SendCommand(cmd);
}


};

