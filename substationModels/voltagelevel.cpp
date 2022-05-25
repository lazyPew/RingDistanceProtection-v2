#include "voltagelevel.h"

#include <QFile>
#include <QDir>
#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>

VoltageLevel::VoltageLevel(QString name, int level, QObject *parent)
    : QObject(parent)
    , _name{name}
    , _levelValue{level}
{
    getNodesFromScv();
}

void VoltageLevel::getNodesFromScv()
{
    QFile nodesFile(":/csvFiles/Buses.csv");
    if (!nodesFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    QTextStream in(&nodesFile);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if(line.split(";")[1].toInt() == _levelValue){
            parseNodes(line);
        }
    }
    qDebug() << _nodesList;
}

void VoltageLevel::parseNodes(QString line)
{
    _nodesList.append(new ConnectivityNode(line.split(";")[0]));
}
