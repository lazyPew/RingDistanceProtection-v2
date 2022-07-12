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
    int configurationIndex() const { return _configurationIndex; }

    void calculateProtectionParameters();
    void readFiles(int index = 1);

private:

    void getTransformersFromCsv();
    void getSystemsFromCsv();
    void getWLinesFromCsv();
    void getTerminalsFromCsv();

private:
    Substation* _substation;
    int _configurationIndex;
};

#endif // CONTROLPANEL_H
