#include "connectivitynode.h"
#include <QDebug>
ConnectivityNode::ConnectivityNode(QString name,
                                   QObject *parent)
    : QObject(parent)
    , _name{name}
{}

void ConnectivityNode::connectSystem(System* s)
{
    _connectedSystems.insert(s->name(), s);
    qDebug() << _name << _connectedSystems;
}

void ConnectivityNode::connectWLine(WLine* w)
{
    _connectedWLines.insert(w->name(), w);
    qDebug() << _name << _connectedWLines;
}

void ConnectivityNode::connectTransformer(Transformer* t)
{
    _connectedTransformers.insert(t->name(), t);
    qDebug() << _name << _connectedTransformers;
}
