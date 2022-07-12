#include "system.h"
#include <QQmlEngine>

System::System(QString csvLine, QObject *parent)
    : ProtectedEquipment (csvLine.split(";")[0], parent)
//    , _name {csvLine.split(";")[0]}
    , _powerS {csvLine.split(";")[1].toDouble()}
    , _resistX {csvLine.split(";")[2].toDouble()}
    , _node{csvLine.split(";")[3]}
{
    registerQmlTypes();
}

System::System(QString name, double power, double resist, QObject *parent)
    : ProtectedEquipment (name, parent)
//    , _name {name}
    , _powerS {power}
    , _resistX {resist}
//    , _node{csvLine.split(";")[3]}
{
    registerQmlTypes();
}



void System::registerQmlTypes() {
    static bool registered = false;
    if (!registered) {
        qmlRegisterUncreatableType<System>(
                    "DataModelTypes", 1, 0,
                    "Terminal", "NOPE"
                    );
        registered = true;
    }
}
