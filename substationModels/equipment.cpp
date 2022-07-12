#include "equipment.h"
#include <QDebug>

Equipment::Equipment(QObject *parent)
    : QObject(parent)
{

}

void Equipment::addWLine(WLine *wline)
{
    if(_wlinesMap.find(wline->name()) != _wlinesMap.end())
        delete _wlinesMap.take(wline->name());
    _wlinesMap[wline->name()] = wline;
}

void Equipment::addSystem(System *system)
{
    if(_systemsMap.find(system->name()) != _systemsMap.end())
        delete _systemsMap.take(system->name());
    _systemsMap[system->name()] = system;
}

WLine *Equipment::getWLine(QString wlineName)    { return _wlinesMap.value(wlineName); }
System *Equipment::getSystem(QString systemName) { return _systemsMap.value(systemName); }

WLine *Equipment::getWLineByIndex(int i)    { return _wlinesMap.values().at(i); }
System *Equipment::getSystemByIndex(int i)  { return _systemsMap.values().at(i); }
