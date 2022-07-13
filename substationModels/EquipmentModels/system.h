#ifndef SYSTEM_H
#define SYSTEM_H

#include <QObject>
#include "protectedequipment.h"

class System : public ProtectedEquipment
{
    Q_OBJECT

//    Q_PROPERTY(QString name
//               READ name
//               CONSTANT)
    Q_PROPERTY(double powerS
               READ powerS
               CONSTANT)
    Q_PROPERTY(double resistX
               READ resistX
               CONSTANT)

public:
    explicit System(QString csvLine, QObject* parent = nullptr);

    explicit System(QString index, double power, double resist, QObject* parent = nullptr);

public slots:
//    QString name() const    {return _name;}
    double powerS() const   {return _powerS;}
    double resistX() const  {return _resistX;}
    QString node() const    {return _node;}

private:
    void registerQmlTypes();

private:
//    QString _name;

    double _powerS;
    double _resistX;
    QString _node;

};

#endif // SYSTEM_H
