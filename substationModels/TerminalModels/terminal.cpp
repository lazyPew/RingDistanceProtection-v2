#include "terminal.h"
#include <QQmlEngine>

Terminal::Terminal(QString index,
                   QObject *parent)
    : QObject(parent)
    , _index{index}
{
    registerQmlTypes();
}

Terminal::Terminal(QString index,
                   ProtectedEquipment* protectedEquipment,
                   QObject *parent)
    : QObject(parent)
    , _protectedEquipmentName{protectedEquipment->index()}
    , _index{index}
    , _protectedEquipment{protectedEquipment}
{
    registerQmlTypes();
}

void Terminal::setProtectedEquipment(ProtectedEquipment* newEquipment)
{
    if(_protectedEquipment != newEquipment)
        _protectedEquipment = newEquipment;
}

void Terminal::setFullName(QString fullName)
{
    if(_terminalFullName != fullName)
        _terminalFullName = fullName;
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
