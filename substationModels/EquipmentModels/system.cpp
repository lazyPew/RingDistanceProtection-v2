#include "system.h"
#include <QQmlEngine>


System::System(QString name, double power, double resist, QObject *parent)
    : ProtectedEquipment (name, parent)
    , _powerS {power}
    , _resistX {resist}
{
    const QRegExp rx(QLatin1Literal("[^0-9]+"));
    const auto&& parts = index().split(rx, QString::SkipEmptyParts);
    setFullName("Система " + parts[0]);
    registerQmlTypes();
}

System::System(QString csvLine, QObject *parent)
    : System (csvLine.split(";")[0],
              csvLine.split(";")[1].toDouble(),
              csvLine.split(";")[2].toDouble(),
              parent)
{
    setNode(csvLine.split(";")[3]);
}


void System::setNode(QString node)
{
    if(node != _node)
        _node = node;
}

void System::registerQmlTypes() {
    static bool registered = false;
    if (!registered) {
        qmlRegisterUncreatableType<System>(
                    "DataModelTypes", 1, 0,
                    "System", "NOPE"
                    );
        registered = true;
    }
}
