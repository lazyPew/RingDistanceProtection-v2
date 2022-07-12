#include "protectedequipment.h"
#include <QQmlEngine>

ProtectedEquipment::ProtectedEquipment(QString name, QObject* parent)
    : QObject(parent)
    , _name {name}
{

}

void ProtectedEquipment::registerQmlTypes() {
    static bool registered = false;
    if (!registered) {
        qmlRegisterUncreatableType<ProtectedEquipment>(
                    "DataModelTypes", 1, 0,
                    "Terminal", "NOPE"
                    );
        registered = true;
    }
}
