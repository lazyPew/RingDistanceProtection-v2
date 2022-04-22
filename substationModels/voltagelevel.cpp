#include "voltagelevel.h"

#include <QFile>
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
    QFile nodesFile("csvFiles/Buses.csv");

    if (!nodesFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&nodesFile);
         while (!in.atEnd()) {
             QString line = in.readLine();
             qDebug() << _name << line.split(",")[0] << " " << (line.split(",")[1]).toInt();
             //process_line(line);
         }
}
