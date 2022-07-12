#include "terminal.h"
#include <QQmlEngine>

Terminal::Terminal(QString name,
                   QObject *parent)
    : QObject(parent)
    , _name{name}
{
    registerQmlTypes();
}

Terminal::Terminal(QString name,
                   ProtectedEquipment* protectedEquipment,
                   QObject *parent)
    : QObject(parent)
    , _name{name}
    , _protectedEquipmentName{protectedEquipment->name()}
    , _protectedEquipment{protectedEquipment}
{
    registerQmlTypes();
}

void Terminal::setProtectedEquipment(ProtectedEquipment* newEquipment)
{
    if(_protectedEquipment != newEquipment)
        _protectedEquipment = newEquipment;
}

void Terminal::registerQmlTypes() {
    static bool registered = false;
    if (!registered) {
        qmlRegisterUncreatableType<Terminal>(
                    "DataModelTypes", 1, 0,
                    "Terminal", "NOPE"
                    );
        registered = true;
    }
}
