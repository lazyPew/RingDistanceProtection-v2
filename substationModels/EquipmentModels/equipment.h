#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <QMap>

#include "system.h"
#include "wline.h"

// change to struct???
class Equipment : public QObject
{
    Q_OBJECT
public:
    Equipment(QObject *parent = nullptr);

    void addWLine(WLine* wline);
    void addSystem(System* system);

    WLine* getWLine(QString);
    System* getSystem(QString);

public slots:
    WLine* getWLineByIndex(int);
    System* getSystemByIndex(int);

private:
    QMap<QString, WLine*> _wlinesMap;
    QMap<QString, System*> _systemsMap;
};

#endif // EQUIPMENT_H
