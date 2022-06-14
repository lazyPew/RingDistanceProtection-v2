#include "terminal.h"

Terminal::Terminal(QString name, QObject *parent)
    : QObject(parent)
    , _name{name}
{

}

Terminal::Terminal(QString name,
                   ProtectedEquipment* protectedEquipment,
                   QObject *parent)
    : QObject(parent)
    , _name{name}
    , _protectedEquipment{protectedEquipment}
{

}
