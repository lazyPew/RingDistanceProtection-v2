#ifndef CONNECTIVITYNODE_H
#define CONNECTIVITYNODE_H

#include <QObject>
#include <QMap>
#include "system.h"
#include "wline.h"
#include "transformer.h"

class ConnectivityNode : public QObject
{
    Q_OBJECT
public:
    explicit ConnectivityNode(QString name,
                              QObject *parent = nullptr);

    void connectSystem(System*);
    void connectWLine(WLine*);
    void connectTransformer(Transformer*);

public slots:
signals:

private:
    QString _name;

    QMap<QString,System*> _connectedSystems;
    QMap<QString,WLine*> _connectedWLines;
    QMap<QString,Transformer*> _connectedTransformers;
};

#endif // CONNECTIVITYNODE_H
