#ifndef CONNECTIVITYNODE_H
#define CONNECTIVITYNODE_H

#include <QObject>
#include <QList>
#include "system.h"
#include "wline.h"

class ConnectivityNode : public QObject
{
    Q_OBJECT
public:
    explicit ConnectivityNode(QObject *parent = nullptr);

signals:

public slots:

private:
//    QList<System*> _connectedSystems;
//    QList<WLine*> _connectedWLines;
};

#endif // CONNECTIVITYNODE_H
