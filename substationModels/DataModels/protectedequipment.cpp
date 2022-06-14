#include "protectedequipment.h"

ProtectedEquipment::ProtectedEquipment(QString name, QObject* parent)
    : QObject(parent)
    , _name {name}
{

}
