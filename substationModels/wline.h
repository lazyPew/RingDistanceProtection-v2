#ifndef WLINE_H
#define WLINE_H

#include "DataModels/protectedequipment.h"

class WLine : public ProtectedEquipment
{
    Q_OBJECT

    Q_PROPERTY(double length
               READ length
               CONSTANT)
    Q_PROPERTY(double resistX
               READ resistX
               CONSTANT)
    Q_PROPERTY(double resistR
               READ resistR
               CONSTANT)
public:
    explicit WLine(QString name,
                   double length,
                   double resistX,
                   double resistR,
                   QObject* parent = nullptr);

    explicit WLine(QString csvLine,
          QObject* parent = nullptr);

public slots:
    double lineImpedance() const    { return _length * _resistX; }

    double length() const           { return _length; }
    double resistX() const          { return _resistX; }
    double resistR() const          { return _resistR; }

    QString node_1() const          { return _node_1; }
    QString node_2() const          { return _node_2; }

private:
//    void registerQmlTypes();

private:
    double _length;
    double _resistX;
    double _resistR;

    QString _node_1;
    QString _node_2;
};

#endif // WLINE_H
