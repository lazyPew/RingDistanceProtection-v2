#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <QObject>
#include "protectedequipment.h"

class Transformer : public ProtectedEquipment
{
    Q_OBJECT

    Q_PROPERTY(double powerS
               READ powerS
               CONSTANT)

    Q_PROPERTY(int hvLevel
               READ hvLevel
               CONSTANT)
    Q_PROPERTY(int mvLevel
               READ mvLevel
               CONSTANT)
    Q_PROPERTY(int lvLevel
               READ lvLevel
               CONSTANT)

    Q_PROPERTY(double uKoefH_M
               READ uKoefH_M
               CONSTANT)
    Q_PROPERTY(double uKoefH_L
               READ uKoefH_L
               CONSTANT)
    Q_PROPERTY(double uKoefM_L
               READ uKoefM_L
               CONSTANT)

    Q_PROPERTY(double regulation
               READ regulation
               CONSTANT)

public:
    explicit Transformer(QString csvLine, QObject *parent = nullptr);

    double transformerImpedanceHV();
    double transformerImpedanceMV();
    double transformerImpedanceLV();
    double distanceProtectionHV();

signals:

public slots:
    QString nodeHV() const      { return _nodeHV; }
    QString nodeMV() const      { return _nodeMV; }
    QString nodeLV() const      { return _nodeLV; }

    double powerS() const       {return _powerS;}

    int hvLevel() const         {return _hvLevel;}
    int mvLevel() const         {return _mvLevel;}
    int lvLevel() const         {return _lvLevel;}

    double uKoefH_M() const     {return _uKoefH_M;}
    double uKoefH_L() const     {return _uKoefH_L;}
    double uKoefM_L() const     {return _uKoefM_L;}

    double regulation() const   { return _regulation; }

private:
    void registerQmlTypes();

private:
    double _powerS;

    int _hvLevel;
    int _mvLevel;
    int _lvLevel;

    double _uKoefH_M;
    double _uKoefH_L;
    double _uKoefM_L;

    double _regulation;

    QString _nodeHV;
    QString _nodeMV;
    QString _nodeLV;

};

#endif // TRANSFORMER_H
