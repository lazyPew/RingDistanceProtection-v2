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
    void readFiles(int index = 1);

private:

    void getTransformersFromCsv(int index);
    void getSystemsFromCsv(int index);
    void getWLinesFromCsv(int index);
    void getTerminalsFromCsv();

private:
    Substation* _substation;
};

#endif // CONTROLPANEL_H
