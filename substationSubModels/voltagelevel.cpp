#include "voltagelevel.h"

VoltageLevel::VoltageLevel(QString name, int level, QObject *parent)
    : QObject(parent)
    , _name{name}
    , _levelValue{level}
{}
