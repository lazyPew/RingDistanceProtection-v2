#include "wline.h"

WLine::WLine(QString name, QObject *parent)
    : QObject(parent)
    , _name{ name }
{

}

double WLine::lineImpedance() const{
    return _length * _resistX;
}
