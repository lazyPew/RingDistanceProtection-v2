#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QObject>

#include "substationModels/substation.h"

class ControlPanel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Substation* substation
               READ substation
               CONSTANT)
public:
    explicit ControlPanel(QObject *parent = nullptr);

signals:
public slots:
    Substation* substation() const { return _substation; }

    void calculateProtectionParameters();

private:
    void readDefaultConfiguration();
    void readDbFiles();

private:
    Substation* _substation;
};

#endif // CONTROLPANEL_H
