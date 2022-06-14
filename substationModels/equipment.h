#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <QMap>

#include "system.h"
#include "wline.h"

class Equipment : public QObject
{
    Q_OBJECT
public:
    Equipment(QObject *parent = nullptr);

    void addWLine(WLine* wline);
    void addSystem(System* system);

    WLine* getWLine(QString);
    System* getSystem(QString);

private:
    QMap<QString, WLine*> _wlinesMap;
    QMap<QString, System*> _systemsMap;
};

#endif // EQUIPMENT_H
