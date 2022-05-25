#include "substation.h"
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
{
    getTransformersFromCsv();
}

void Substation::calculateProtectionParameters()
{

}

void Substation::getTransformersFromCsv()
{
    QFile transformerFile(":/csvFiles/Transformers.csv");
    if (!transformerFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    QTextStream in(&transformerFile);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if(line.split(";")[0].contains("T"))
            addTransformer(line);
    }
}

void Substation::addTransformer(QString line)
{
    Transformer* transformer = new Transformer(line);
    _transformersMap.insert(transformer->name(), transformer);
    connectTransformerToNodes(transformer);
}

void Substation::connectTransformerToNodes(Transformer* transformer)
{
    _hvLevel->getNodeByName(transformer->nodeHV())->connectTransformer(transformer);
    _mvLevel->getNodeByName(transformer->nodeMV())->connectTransformer(transformer);
    _lvLevel->getNodeByName(transformer->nodeLV())->connectTransformer(transformer);
}
