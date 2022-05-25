#ifndef VOLTAGELEVEL_H
#define VOLTAGELEVEL_H

#include <QObject>
#include "transformer.h"
#include "connectivitynode.h"

class VoltageLevel : public QObject
{
    Q_OBJECT
public:
    VoltageLevel(QString, int, QObject *parent = nullptr);

    void getNodesFromScv();

signals:

public slots:
    QString name() const                        { return _name; }
    int levelValue() const                      { return _levelValue; }

    QList<ConnectivityNode*> nodesList() const  { return _nodesList; }

private:
    void parseNodes(QString);

private:
    QString _name;
    int _levelValue;

    QList<ConnectivityNode*> _nodesList;
    QList<Transformer*> _transformersList;
};

#endif // VOLTAGELEVEL_H
