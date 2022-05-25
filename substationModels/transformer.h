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

signals:

public slots:
    QString name() const {return _name;}

private:
    QString _name;

    double _powerS;

    int _hvLevel;
    int _mvLevel;
    int _lvLevel;

    double _uKoefH_L;
    double _uKoefH_M;
    double _uKoefM_L;

//    ConnectivityNode* _nodeHV;
//    ConnectivityNode* _nodeMV;
//    ConnectivityNode* _nodeLV;

    double _regulation;
};

#endif // TRANSFORMER_H
