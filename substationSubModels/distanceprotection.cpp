#include "distanceprotection.h"

DistanceProtectionTerminal::DistanceProtectionTerminal(QString name, QObject *parent)
    : Terminal(name, parent)
{}

void DistanceProtectionTerminal::calculateParameters()
{
    calculateFirstStep_DP();
    calculateSecondStep_DP();
    calculateThirdStep_DP();
}

void DistanceProtectionTerminal::calculateFirstStep_DP(){
    _firstZ = 0.87 * (_protectionObject->lineImpedance());
    _firstT = 0;
}

void DistanceProtectionTerminal::calculateSecondStep_DP()
{

}

void DistanceProtectionTerminal::calculateThirdStep_DP()
{

}
