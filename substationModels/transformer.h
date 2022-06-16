#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <QObject>
//#include "connectivitynode.h"

class Transformer : public QObject
{
    Q_OBJECT
public:
    explicit Transformer(QObject *parent = nullptr);

    explicit Transformer(QString csvLine, QObject *parent = nullptr);

    double transformerImpedanceHV();
    double transformerImpedanceMV();
    double transformerImpedanceLV();
    double distanceProtectionHV();

signals:

public slots:
    QString name() const        { return _name; }
    QString nodeHV() const      { return _nodeHV; }
    QString nodeMV() const      { return _nodeMV; }
    QString nodeLV() const      { return _nodeLV; }
    double regulation() const   { return _regulation; }
private:
    QString _name;

    double _powerS;

    int _hvLevel;
    int _mvLevel;
    int _lvLevel;

    double _uKoefH_L;
    double _uKoefH_M;
    double _uKoefM_L;

    double _regulation;

    QString _nodeHV;
    QString _nodeMV;
    QString _nodeLV;

};

#endif // TRANSFORMER_H
