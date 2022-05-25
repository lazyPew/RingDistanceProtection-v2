#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QObject>

#include "substationModels/substation.h"

class ControlPanel : public QObject
{
    Q_OBJECT
public:
    explicit ControlPanel(QObject *parent = nullptr);

signals:
public slots:
    void calculateProtectionParameters();

private:
    void readDefaultConfiguration();
    void readDbFiles();

private:
    Substation* _substation;
};

#endif // CONTROLPANEL_H
