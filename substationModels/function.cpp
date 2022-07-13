#include "function.h"

Function::Function(QObject *parent)
    : QObject(parent)
    , _equipment{new Equipment()}
{
    
}

void Function::addWLineToEquipment(WLine* wline)
{
    equipment()->addWLine(wline);
}

void Function::addSystemToEquipment(System* system)
{
    equipment()->addSystem(system);

}

void Function::addTerminal(Terminal* terminal)
{
    _terminalsList.append(terminal);
}
