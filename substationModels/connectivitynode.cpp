#include "connectivitynode.h"
#include <QDebug>

ConnectivityNode::ConnectivityNode(QString name,
                                   QObject *parent)
    : QObject(parent)
    , _name{name}
{}

System* ConnectivityNode::generationInNode()
{
    if(numbersOfSystems() == 1){
        return _connectedSystems.first();
    }
    return nullptr;
}

Transformer *ConnectivityNode::chooseTransformer()
{
    auto item = _connectedTransformers.begin();
    std::advance(item, rand() % numbersOfTransformers());
    return item.value();
}

void ConnectivityNode::connectSystem(System* s)             { _connectedSystems.insert(s->index(), s); }
void ConnectivityNode::connectWLine(WLine* w)               { _connectedWLines.insert(w->index(), w); }
void ConnectivityNode::connectTransformer(Transformer* t)   { _connectedTransformers.insert(t->name(), t); }

int ConnectivityNode::numbersOfSystems()        { return _connectedSystems.size(); }
int ConnectivityNode::numbersOfWLines()         { return _connectedWLines.size(); }
int ConnectivityNode::numbersOfTransformers()   { return _connectedTransformers.size(); }

System *ConnectivityNode::getSystemByName(QString name)             { return _connectedSystems.value(name); }
WLine *ConnectivityNode::getWLineByName(QString name)               { return _connectedWLines.value(name); }
Transformer *ConnectivityNode::getTransformerByName(QString name)   { return _connectedTransformers.value(name); }
