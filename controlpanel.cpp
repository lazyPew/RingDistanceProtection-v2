#include "controlpanel.h"
#include <QFile>
#include <QDebug>

ControlPanel::ControlPanel(QObject *parent)
    : QObject(parent)
    , _substation{ new Substation("ПС 110/35",115,35,10)}
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
    getSystemsFromCsv(index);
    getTransformersFromCsv(index);
    getWLinesFromCsv(index);
}


void ControlPanel::getTransformersFromCsv(int index)
{
    QFile transformerFile(":/csvFiles/ss" + QString::number(index) + "/Transformers.csv");
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

void ControlPanel::getSystemsFromCsv(int index)
{
    QFile systemsFile(":/csvFiles/ss" + QString::number(index) + "/Systems.csv");
    if (!systemsFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    QTextStream in(&systemsFile);
    while (!in.atEnd()) {
        QString line = in.readLine();
        qDebug() << line;
        if(line.split(";")[0].contains("S"))
            substation()->parseSystem(line);
    }
}

void ControlPanel::getWLinesFromCsv(int index)
{
    QFile wlinesFile(":/csvFiles/ss" + QString::number(index) + "/WLines.csv");
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
