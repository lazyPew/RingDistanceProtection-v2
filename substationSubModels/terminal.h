#ifndef TERMINAL_H
#define TERMINAL_H

//#include "function.h"
#include "QObject"
#include "connectivitynode.h"

class Terminal : public QObject
{
    Q_OBJECT
public:
    Terminal(QObject *parent = nullptr);
};


#endif // TERMINAL_H
