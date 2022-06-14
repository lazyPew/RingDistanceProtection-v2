#include "system.h"

System::System(QString csvLine, QObject *parent)
    : QObject(parent)
    , _name {csvLine.split(";")[0]}
    , _powerS {csvLine.split(";")[1].toDouble()}
    , _resistX {csvLine.split(";")[2].toDouble()}
    , _node{csvLine.split(";")[3]}
{

}

System::System(QString name, double power, double resist, QObject *parent)
    : QObject(parent)
    , _name {name}
    , _powerS {power}
    , _resistX {resist}
//    , _node{csvLine.split(";")[3]}
{

}


