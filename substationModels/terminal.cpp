#include "terminal.h"

Terminal::Terminal(QString name,
//                   Function* func,
                   QObject *parent)
    : QObject(parent)
    , _name{name}
//    , _function{func}
{

}

Terminal::Terminal(QString name,
                   ProtectedEquipment* protectedEquipment,
//                   Function* func,
                   QObject *parent)
    : QObject(parent)
//    : Terminal(name,/*func,*/parent)
    , _name{name}
//    , _function{func}
    , _protectedEquipment{protectedEquipment}
{

}

