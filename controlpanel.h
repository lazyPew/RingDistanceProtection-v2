#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QObject>

#include "substationSubModels/substation.h"

class ControlPanel : public QObject
{
    Q_OBJECT
public:
    explicit ControlPanel(QObject *parent = nullptr);

signals:
public slots:

private:
    void readDefaultConfiguration();
private:
    Substation _substation;
};

#endif // CONTROLPANEL_H
