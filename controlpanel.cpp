#include "controlpanel.h"
#include <QFile>
#include <QDebug>

ControlPanel::ControlPanel(QObject *parent)
    : QObject(parent)
    , _substation{ new Substation("ПС 110/35",115,35,10)}
    , _configurationIndex(0)
{
    readFiles();
    getTerminalsFromCsv();
}

void ControlPanel::calculateProtectionParameters()
{
    _substation->calculateProtectionParameters();
}

void ControlPanel::readFiles(int index)
{
    if (index != _configurationIndex){
        _configurationIndex = index;
        getSystemsFromCsv();
        getTransformersFromCsv();
        getWLinesFromCsv();
    }
}


void ControlPanel::getTransformersFromCsv()
{
    QFile transformerFile(":/csvFiles/ss" + QString::number(_configurationIndex) + "/Transformers.csv");
    if (!transformerFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    QTextStream in(&transformerFile);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if(line.split(";")[0].contains("T"))
            substation()->parseTransformer(line);
    }
    transformerFile.close();
}

void ControlPanel::getSystemsFromCsv()
{
    QFile systemsFile(":/csvFiles/ss" + QString::number(_configurationIndex) + "/Systems.csv");
    if (!systemsFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    QTextStream in(&systemsFile);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if(line.split(";")[0].contains("S"))
            substation()->parseSystem(line);
    }
}

void ControlPanel::getWLinesFromCsv()
{
    QFile wlinesFile(":/csvFiles/ss" + QString::number(_configurationIndex) + "/WLines.csv");
    if (!wlinesFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    QTextStream in(&wlinesFile);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if(line.split(";")[0].contains("W"))
            substation()->parseWLine(line);
    }
}

void ControlPanel::getTerminalsFromCsv()
{
    QFile terminalsFile(":/csvFiles/ss1/DistanceProtections.csv");
    if (!terminalsFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    QTextStream in(&terminalsFile);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if(line.split(";")[0].contains("dp"))
            substation()->parseTerminal(line);
    }
}
