#include "connectivitynode.h"

ConnectivityNode::ConnectivityNode(QString name,
                                   QObject *parent)
    : QObject(parent)
    , _name{name}
{}

void ConnectivityNode::connectSystem(System* s)
{
    _connectedSystems.insert(s->name(), s);
}

void ConnectivityNode::connectWLine(WLine* w)
{
    _connectedWLines.insert(w->name(), w);
}

void ConnectivityNode::connectTransformer(Transformer* t)
{
    _connectedTransformers.insert(t->name(), t);
}
