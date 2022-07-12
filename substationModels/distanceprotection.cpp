#include "distanceprotection.h"
#include <limits.h>
#include <QQmlEngine>
#include <math.h>
#include <exception>
#include <QDebug>

DistanceProtectionTerminal::DistanceProtectionTerminal(
        QString csvLine,
        Function* parentModel,
        QObject *parent)
    : Terminal(csvLine.split(";")[0], parent)
    , _function{parentModel}
{
    registerQmlTypes();
}

DistanceProtectionTerminal::DistanceProtectionTerminal(
        QString name,
        WLine* protectedEquipment,
        Function* parentModel,
        QObject *parent)
    : Terminal(name, protectedEquipment, parent)
    , _function{parentModel}
    , _firstZ(-1)
    , _secondZ(-1)
    , _thirdZ(-1)
    , _firstT(-1)
    , _secondT(-1)
    , _thirdT(-1)
{
    registerQmlTypes();
}

DistanceProtectionTerminal::DistanceProtectionTerminal(
        QString name,
        WLine *protectedEquipment,
        ConnectivityNode *installNode,
        ConnectivityNode *directionNode,
        Function* parentModel,
        QObject *parent)
    : DistanceProtectionTerminal(name, protectedEquipment, parentModel, parent)
{
    registerQmlTypes();
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

QString DistanceProtectionTerminal::getResults()
{
    return ("\n" + name() + ": " + (_firstZ < 0
            ? "to be calculated"
            : "\n   1st: z = " + QString::number(_firstZ) + "\n        t = " + QString::number(_firstT) + "\n"
    "   2nd: z = " + QString::number(_secondZ) + "\n        t = " + QString::number(_secondT) + "\n"
    "   3rd: z = " + QString::number(_thirdZ) + "\n        t = " + QString::number(_thirdT)));
}

WLine* DistanceProtectionTerminal::protectedEquipmentAsWLine()
{
    return static_cast<WLine*>(protectedEquipment());
}

void DistanceProtectionTerminal::calculateFirstStep_DP(){
    _firstZ = 0.87 * (protectedEquipmentAsWLine()->lineImpedance());
    _firstT = 0;
}

void DistanceProtectionTerminal::calculateSecondStep_DP()
{
    if (_secondZ > 0)
        return;

    double delta_T = 0.5;
    double bfp_T = 0.3;
    double k_sense_II = 1.25;
    DistanceProtectionTerminal* dp_next = findNextDPTerminal();
    if(dp_next->firstZ() < 0)
        dp_next->calculateFirstStep_DP();

    double z_test1 = 0.87 * (protectedEquipmentAsWLine()->lineImpedance() + 0.9 * dp_next->firstZ());
    _secondT= bfp_T + delta_T;

    if (dp_next->installNode()->numbersOfTransformers() > 0){
        Transformer* tr = chooseTransformer(dp_next);
        double z_test2 = 0.87 * (protectedEquipmentAsWLine()->lineImpedance() +
                         (1.0 / dp_next->installNode()->numbersOfTransformers()) * (
                         (pow(1-(tr->regulation()/100),2)*
                          tr->transformerImpedanceHV() +
                         tr->transformerImpedanceMV())));

        if (z_test1 > z_test2){
            if (k_sense_II > z_test2 / protectedEquipmentAsWLine()->lineImpedance()){
                z_test2 = 0.87 * (protectedEquipmentAsWLine()->lineImpedance() +
                          0.9 * tr->distanceProtectionHV());
                _secondT += delta_T;
            }
            _secondZ = z_test2;
            return;
        }
    }

    if (k_sense_II > (z_test1 / protectedEquipmentAsWLine()->lineImpedance())){
        if(dp_next->secondZ() < 0){
            dp_next->secondStepCalculation();
        }
        z_test1 = 0.87 * (protectedEquipmentAsWLine()->lineImpedance() +
                          0.9 * (dp_next->secondZ()));
        _secondT += delta_T;
    }
    _secondZ = z_test1;
}

void DistanceProtectionTerminal::calculateThirdStep_DP()
{
    if (_thirdZ > 0)
        return;

    double delta_T = 0.5;
    double k_sense_III = 1.2;
    DistanceProtectionTerminal* dp_next = findNextDPTerminal();
    QList<double> z_test;
    double k = infeedCoef();
    if (generationFromBehind() != nullptr && installNode()->numbersOfSystems() > 0)
        z_test.append(k_sense_III * (protectedEquipmentAsWLine()->lineImpedance() + dp_next->protectedEquipmentAsWLine()->lineImpedance()));
    if (dp_next->installNode()->numbersOfTransformers() > 0){
        Transformer* t = dp_next->installNode()->chooseTransformer();
        z_test.append(k_sense_III * (protectedEquipmentAsWLine()->lineImpedance() +
                (t->transformerImpedanceLV() + (pow((1+t->regulation()/100),2) * t->transformerImpedanceHV()) / k)));
    }
    else
        z_test.append(
            k_sense_III * (protectedEquipmentAsWLine()->lineImpedance() + (dp_next->protectedEquipmentAsWLine()->lineImpedance() / k)));
    _thirdZ = *std::max_element(z_test.begin(),z_test.end());
    if (installNode()->numbersOfTransformers() > 0){
        if (_secondT < 0)
            secondStepCalculation();
        _thirdT = _secondT + delta_T;
    }
    else{
        if(dp_next->thirdT() < 0)
            dp_next->thirdStepCalculation();
        _thirdT = dp_next->thirdT()+ delta_T;
    }
}

double DistanceProtectionTerminal::infeedCoef()
{
    double num = 0;
    double denum = 0;
    System* s_1st;
    System* s_2nd = nullptr;
    if (installNode()->numbersOfSystems() > 0)
    {
        s_1st = installNode()->generationInNode();
        if (generationFromBehind() != nullptr){
            s_2nd = generationFromBehind();
            num += findNextDPTerminal()->protectedEquipmentAsWLine()->lineImpedance();
            denum += findNextDPTerminal()->protectedEquipmentAsWLine()->lineImpedance();
        }
        else if(findNextDPTerminal()->installNode()->generationInNode() != nullptr){
            s_2nd = findNextDPTerminal()->installNode()->generationInNode();
        }

        num += s_2nd->resistX();
        denum += s_1st->resistX() + protectedEquipmentAsWLine()->lineImpedance() + s_2nd->resistX();
    }
    else{
        s_1st = generationFromBehind();
        s_2nd = findNextDPTerminal()->installNode()->generationInNode();
        num += s_2nd->resistX();
        denum += s_1st->resistX() + s_2nd->resistX() + protectedEquipmentAsWLine()->lineImpedance()
                + findNextDPTerminal()->protectedEquipmentAsWLine()->lineImpedance();
    }
    return num / denum;
}

Transformer *DistanceProtectionTerminal::chooseTransformer(DistanceProtectionTerminal* dp_next)
{
    return dp_next->installNode()->chooseTransformer();
}

DistanceProtectionTerminal *DistanceProtectionTerminal::findNextDPTerminal()
{
    for(auto next : _function->getTerminals()){
        DistanceProtectionTerminal* next_dp = static_cast<DistanceProtectionTerminal*>(next);
        if(next_dp != nullptr
                && next_dp->installNode() == directionNode()
                && next_dp->directionNode() != installNode()){
            return next_dp;
        }
    }
}

System* DistanceProtectionTerminal::generationFromBehind()
{
    for(auto prev: _function->getTerminals()){
        DistanceProtectionTerminal* prev_dp = static_cast<DistanceProtectionTerminal*>(prev);
        if(prev_dp != nullptr
                && prev_dp->installNode() != directionNode()
                && prev_dp->directionNode() == installNode()){
            return prev_dp->installNode()->generationInNode();
        }
    }
}

void DistanceProtectionTerminal::resetParameters()
{
    _firstZ = -1;
    _firstT = -1;
    _secondZ = -1;
    _secondT = -1;
    _thirdZ = -1;
    _thirdT = -1;
}

void DistanceProtectionTerminal::registerQmlTypes() {
    static bool registered = false;
    if (!registered) {
        qmlRegisterUncreatableType<DistanceProtectionTerminal>(
                    "DataModelTypes", 1, 0,
                    "Terminal", "NOPE"
                    );
//        qRegisterMetaType<Error>("Error");
//        qRegisterMetaType<FeedbackState>("FeedbackState");
        registered = true;
    }
}

