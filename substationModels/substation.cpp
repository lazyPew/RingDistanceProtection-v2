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
    getSystemsFromCsv();
    getTransformersFromCsv();
    getWLinesFromCsv();

    getTerminalsFromCsv();
}

void Substation::calculateProtectionParameters()
{
    for(auto t: function()->getTerminals())
        t->calculateParameters();
}

void Substation::getTransformersFromCsv()
{
    QFile transformerFile(":/csvFiles/ss1/Transformers.csv");
    if (!transformerFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    QTextStream in(&transformerFile);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if(line.split(";")[0].contains("T"))
            addTransformer(line);
    }
    transformerFile.close();
}

void Substation::getSystemsFromCsv()
{
    QFile systemsFile(":/csvFiles/ss1/Systems.csv");
    if (!systemsFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    QTextStream in(&systemsFile);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if(line.split(";")[0].contains("S"))
            addSystem(line);
    }
}

void Substation::getWLinesFromCsv()
{
    QFile wlinesFile(":/csvFiles/ss1/WLines.csv");
    if (!wlinesFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    QTextStream in(&wlinesFile);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if(line.split(";")[0].contains("W"))
            addWLine(line);
    }
}

void Substation::addTransformer(QString line)
{
    Transformer* transformer = new Transformer(line);
    _transformersMap.insert(transformer->name(), transformer);
    connectTransformerToNodes(transformer);
}

void Substation::addSystem(QString line)
{
    System* system = new System(line);
    function()->addSystemToEquipment(system);
    connectSystemToNodes(system);
}

void Substation::addWLine(QString line)
{
    WLine* wline = new WLine(line);
    function()->addWLineToEquipment(wline);
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


void Substation::getTerminalsFromCsv()
{
    QFile terminalsFile(":/csvFiles/ss1/DistanceProtections.csv");
    if (!terminalsFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    QTextStream in(&terminalsFile);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if(line.split(";")[0].contains("dp"))
            addTerminal(line);
    }
}

void Substation::addTerminal(QString line)
{
    function()->addTerminal(
                new DistanceProtectionTerminal(
                    line.split(";")[0],
                    function()->equipment()->getWLine(line.split(";")[1]),
                    _hvLevel->getNodeByName(line.split(";")[2]),
                    _hvLevel->getNodeByName(line.split(";")[3]),
                    function()));
}
