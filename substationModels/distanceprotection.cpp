#include "distanceprotection.h"
#include <limits.h>
#include <QDebug>

DistanceProtectionTerminal::DistanceProtectionTerminal(
        QString csvLine,
        QObject *parent)
    : Terminal(csvLine.split(";")[0], parent)
{}

DistanceProtectionTerminal::DistanceProtectionTerminal(
        QString name,
        WLine* protectedEquipment,
        QObject *parent)
    : Terminal(name, protectedEquipment, parent)
//    , _protectionObject{protectionObject}
{}

DistanceProtectionTerminal::DistanceProtectionTerminal(
        QString name,
        WLine *protectedEquipment,
        ConnectivityNode *installNode,
        ConnectivityNode *directionNode,
        QObject *parent)
    : DistanceProtectionTerminal(name, protectedEquipment, parent)
{
    connectToNodes(installNode,directionNode);
}

void DistanceProtectionTerminal::connectToNodes(
        ConnectivityNode *installNode,
        ConnectivityNode *directionNode)
{
    _installNode = installNode;
    _directionNode = directionNode;
}

void DistanceProtectionTerminal::calculateParameters()
{
    resetParameters();

    calculateFirstStep_DP();
    calculateSecondStep_DP();
    calculateThirdStep_DP();
}

WLine* DistanceProtectionTerminal::protectedEquipmentAsWLine()
{
    return static_cast<WLine*>(protectedEquipment());
}

void DistanceProtectionTerminal::calculateFirstStep_DP(){
    _firstZ = 0.87 * (protectedEquipmentAsWLine()->lineImpedance());
    _firstT = 0;
    qDebug() << name() << _firstZ << _firstT;
}

void DistanceProtectionTerminal::calculateSecondStep_DP()
{

}

void DistanceProtectionTerminal::calculateThirdStep_DP()
{

}

//DistanceProtectionTerminal *DistanceProtectionTerminal::findNextDPTerminal()
//{
//    for(auto dp_new : )
//}

void DistanceProtectionTerminal::resetParameters()
{
    _firstZ = std::numeric_limits<double>::quiet_NaN();
    _firstT = std::numeric_limits<double>::quiet_NaN();
    _secondZ = std::numeric_limits<double>::quiet_NaN();
    _secondT = std::numeric_limits<double>::quiet_NaN();
    _thirdZ = std::numeric_limits<double>::quiet_NaN();
    _thirdT = std::numeric_limits<double>::quiet_NaN();
}
