#ifndef CONNECTIVITYNODE_H
#define CONNECTIVITYNODE_H

#include <QObject>

class ConnectivityNode : public QObject
{
    Q_OBJECT
public:
    explicit ConnectivityNode(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CONNECTIVITYNODE_H