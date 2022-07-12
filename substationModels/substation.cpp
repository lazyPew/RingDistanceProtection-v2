#include "substation.h"
#include "distanceprotection.h"
#include <QDebug>
#include <QFile>

Substation::Substation(QObject *parent)
    : QObject(parent)
{}

Substation::Substation(QString name,
                       int hv,
                       int mv,
                       int lv,
                       QObject *parent)
    : QObject(parent)
    , _name{name}
    , _hvLevel(new VoltageLevel("HV",hv))
    , _mvLevel(new VoltageLevel("MV",mv))
    , _lvLevel(new VoltageLevel("LV",lv))
    , _function{new Function()}
{
//    readFiles();
}

void Substation::calculateProtectionParameters()
{
    for(auto t: functionObj()->getTerminals()){

        t->resetParameters();
        t->calculateParameters();
    }
}

//void Substation::readFiles(int index)
//{
////    getSystemsFromCsv(index);
////    getTransformersFromCsv(index);
////    getWLinesFromCsv(index);

////    getTerminalsFromCsv();

//}


void Substation::parseTransformer(QString line)
{
    Transformer* transformer = new Transformer(line);
    if(_transformersMap.find(transformer->name()) != _transformersMap.end())
        delete _transformersMap.take(transformer->name());
    _transformersMap.insert(transformer->name(), transformer);
    connectTransformerToNodes(transformer);
}

void Substation::parseSystem(QString line)
{
    System* system = new System(line);
    functionObj()->addSystemToEquipment(system);
    connectSystemToNodes(system);
}

void Substation::parseWLine(QString line)
{
    WLine* wline = new WLine(line);
    functionObj()->addWLineToEquipment(wline);
    connectWLineToNodes(wline);
}

void Substation::connectTransformerToNodes(Transformer* transformer)
{
    _hvLevel->getNodeByName(transformer->nodeHV())->connectTransformer(transformer);
    _mvLevel->getNodeByName(transformer->nodeMV())->connectTransformer(transformer);
    _lvLevel->getNodeByName(transformer->nodeLV())->connectTransformer(transformer);
}

void Substation::connectSystemToNodes(System* system)
{
    _hvLevel->getNodeByName(system->node())->connectSystem(system);
}

void Substation::connectWLineToNodes(WLine* wline)
{
    _hvLevel->getNodeByName(wline->node_1())->connectWLine(wline);
    _hvLevel->getNodeByName(wline->node_2())->connectWLine(wline);
}

void Substation::parseTerminal(QString line)
{
    functionObj()->addTerminal(
                new DistanceProtectionTerminal(
                    line.split(";")[0],
                    functionObj()->equipment()->getWLine(line.split(";")[1]),
                    _hvLevel->getNodeByName(line.split(";")[2]),
                    _hvLevel->getNodeByName(line.split(";")[3]),
                    functionObj()));
}
