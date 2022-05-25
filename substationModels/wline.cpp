#include "wline.h"

WLine::WLine(QString name, QObject *parent)
    : ProtectedEquipment(parent)
    , _name{ name }
{

}
