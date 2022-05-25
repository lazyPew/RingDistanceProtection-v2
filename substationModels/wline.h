#ifndef WLINE_H
#define WLINE_H

#include "DataModels/protectedequipment.h"

class WLine : public ProtectedEquipment
{
    Q_OBJECT

public:
    WLine(QString name = "", QObject* parent = nullptr);

public slots:
    QString name() const         { return _name; }
    double lineImpedance() const { return _length * _resistX; }

private:
    QString _name;

    double _resistX;
    double _resistR;
    double _length;
};

#endif // WLINE_H
