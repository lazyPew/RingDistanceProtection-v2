#ifndef WLINE_H
#define WLINE_H

#include "DataModels/protectedequipment.h"

class WLine : public ProtectedEquipment
{
    Q_OBJECT

public:
    explicit WLine(QString name,
                   double length,
                   double resistX,
                   double resistR,
                   QObject* parent = nullptr);

    explicit WLine(QString csvLine,
          QObject* parent = nullptr);

public slots:
//    QString name() const            { return _name; }
    double lineImpedance() const    { return _length * _resistX; }
    QString node_1() const          { return _node_1; }
    QString node_2() const          { return _node_2; }

private:
//    QString _name;

    double _length;
    double _resistX;
    double _resistR;

    QString _node_1;
    QString _node_2;
};

#endif // WLINE_H
