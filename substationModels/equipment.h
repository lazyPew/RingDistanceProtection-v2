#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "QObject"
#include "system.h"
#include "wline.h"

class Equipment : public QObject
{
    Q_OBJECT
public:
    Equipment(QObject *parent = nullptr);

private:
    QList<WLine*> _wlinesList;
    QList<System*> _systemsList;
};

#endif // EQUIPMENT_H
