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

    ConnectivityNode* getNodeByName(QString);

signals:

public slots:
    QString name() const                                { return _name; }
    int levelValue() const                              { return _levelValue; }

    QMap<QString,ConnectivityNode*> nodesList() const   { return _nodesMap; }

private:
    void getNodesFromScv();
    void parseNodes(QString);

private:
    QString _name;
    int _levelValue;

    QMap<QString,ConnectivityNode*> _nodesMap;
    QList<Transformer*> _transformersList;
};

#endif // VOLTAGELEVEL_H
