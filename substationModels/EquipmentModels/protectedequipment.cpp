#include "protectedequipment.h"
#include <QQmlEngine>

ProtectedEquipment::ProtectedEquipment(QString index, QObject* parent)
    : QObject(parent)
    , _index {index}
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
