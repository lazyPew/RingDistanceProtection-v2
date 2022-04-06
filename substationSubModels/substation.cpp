#include "substation.h"

Substation::Substation(QObject *parent) : QObject(parent)
{}

Substation::Substation(QString name,
                       int hv,
                       int mv,
                       int lv,
                       QObject *parent)
    : QObject(parent)
    , _name{name}
    , _hvLevel(new VoltageLevel("HV",hv))
    , _mvLevel(new VoltageLevel("MV",mv))
    , _lvLevel(new VoltageLevel("LV",lv))
{

}
