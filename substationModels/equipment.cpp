#include "equipment.h"
#include <QDebug>

Equipment::Equipment(QObject *parent)
    : QObject(parent)
{

}

void Equipment::addWLine(WLine *wline)
{
    _wlinesMap.insert(wline->name(), wline);
}

void Equipment::addSystem(System *system)
{
    _systemsMap.insert(system->name(), system);
}

WLine *Equipment::getWLine(QString wlineName)    { return _wlinesMap.value(wlineName); }
System *Equipment::getSystem(QString systemName) { return _systemsMap.value(systemName); }
