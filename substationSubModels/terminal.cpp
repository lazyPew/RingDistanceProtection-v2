#include "terminal.h"

Terminal::Terminal(QString name, QObject *parent)
    : QObject(parent)
    , _name{name}
{

}
