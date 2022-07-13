#include "equipment.h"
#include <QDebug>

Equipment::Equipment(QObject *parent)
    : QObject(parent)
{

}

void Equipment::addWLine(WLine *wline)
{
    if(_wlinesMap.find(wline->index()) != _wlinesMap.end())
        delete _wlinesMap.take(wline->index());
    _wlinesMap[wline->index()] = wline;
}

void Equipment::addSystem(System *system)
{
    if(_systemsMap.find(system->index()) != _systemsMap.end())
        delete _systemsMap.take(system->index());
    _systemsMap[system->index()] = system;
}

WLine *Equipment::getWLine(QString wlineName)    { return _wlinesMap.value(wlineName); }
System *Equipment::getSystem(QString systemName) { return _systemsMap.value(systemName); }

WLine *Equipment::getWLineByIndex(int i)    { return _wlinesMap.values().at(i); }
System *Equipment::getSystemByIndex(int i)  { return _systemsMap.values().at(i); }
