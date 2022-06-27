#include "distanceprotection.h"
#include <limits.h>
#include <math.h>
#include <exception>
#include <QDebug>

DistanceProtectionTerminal::DistanceProtectionTerminal(
        QString csvLine,
        Function* parentModel,
        QObject *parent)
    : Terminal(csvLine.split(";")[0], parent)
    , _function{parentModel}
{}

DistanceProtectionTerminal::DistanceProtectionTerminal(
        QString name,
        WLine* protectedEquipment,
        Function* parentModel,
        QObject *parent)
    : Terminal(name, protectedEquipment, parent)
    , _function{parentModel}
{}

DistanceProtectionTerminal::DistanceProtectionTerminal(
        QString name,
        WLine *protectedEquipment,
        ConnectivityNode *installNode,
        ConnectivityNode *directionNode,
        Function* parentModel,
        QObject *parent)
    : DistanceProtectionTerminal(name, protectedEquipment, parentModel, parent)
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
    if (!isnan(_secondZ))
        return;

    double delta_T = 0.5;
    double bfp_T = 0.3;
    double k_sense_II = 1.25;
    DistanceProtectionTerminal* dp_next = findNextDPTerminal();
    double z_test1 = 0.87 * (protectedEquipmentAsWLine()->lineImpedance() + 0.9 * dp_next->firstZ());
    _secondT= bfp_T + delta_T;

    if (dp_next->installNode()->numbersOfTransformers() > 0){
        Transformer* tr = chooseTransformer(dp_next);
        double z_test2 = 0.87 * (protectedEquipmentAsWLine()->lineImpedance() +
                         (1 / dp_next->installNode()->numbersOfTransformers()) * (
                         (pow(1-tr->regulation()/100,2))*tr->transformerImpedanceHV() +
                         tr->transformerImpedanceMV()));
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

    if (k_sense_II > z_test1 / protectedEquipmentAsWLine()->lineImpedance()){
        try
        {
            if(isnan(dp_next->secondZ()))
                throw std::runtime_error("need to calculate second step Z for next terminal");
        }
        catch (std::runtime_error err){
            dp_next->secondStepCalculation();
        }
        z_test1 = 0.87 * (protectedEquipmentAsWLine()->lineImpedance() +
                  0.9 * (dp_next->secondZ()));
        _secondT += delta_T;
    }
    _secondZ = z_test1;
    qDebug() << name() << _secondZ << _secondT;
}

void DistanceProtectionTerminal::calculateThirdStep_DP()
{
    double delta_T = 0.5;
    double k_sense_III = 1.2;
    DistanceProtectionTerminal* dp_next = findNextDPTerminal();
    double z_test [] = {};
//    a = self.name
    double k = infeedCoef();
//    if (self.GenerationFromBehind(sub) != None and len(self.node.have_S) > 0):
//        z_test.append(k_sense_III * (self.obj.LineImpedance() + dp_next.obj.LineImpedance()))
//    if (len(dp_next.node.have_T) > 0):
//        t = dp_next.node.ChooseTransformer()
//        z_test.append(k_sense_III * (self.obj.LineImpedance() +
//                (t.TransformerImpedanceLV() + ((1+t.reg/100)**2)*t.TransformerImpedanceHV()) / self.InfeedCoef(sub)))
//        b = t.reg
//        a = self.t_third
//        c = t.TransformerImpedanceHV()

//    else:
//        z_test.append(
//            k_sense_III * (self.obj.LineImpedance() + (dp_next.obj.LineImpedance() / self.InfeedCoef(sub))))
//    self.z_third = max(z_test)
//    if (len(self.node.have_T) > 0):
//        a = self.t_second
//        self.t_third = self.t_second + delta_T
//        a = self.t_third
//    else:
//        try:
//            self.t_third = self.FindNextDP(sub).t_third + delta_T
//        except TypeError:
//            self.FindNextDP(sub).third_step_dp(sub)
//            a = self.t_third
//            self.t_third = self.FindNextDP(sub).t_third + delta_T
//            a = self.t_third
    //            a = self.t_third
}

double DistanceProtectionTerminal::infeedCoef()
{
    double num = 0;
    double denum = 0;
    System* s_1st;
    System* s_2nd;
    if (installNode()->numbersOfSystems() > 0)
    {
        s_1st = installNode()->generationInNode();
        if (generationFromBehind() != nullptr){
            System* s_2nd = generationFromBehind();
            num += findNextDPTerminal()->protectedEquipmentAsWLine()->lineImpedance();
            denum += findNextDPTerminal()->protectedEquipmentAsWLine()->lineImpedance();
        }
        else if(findNextDPTerminal()->installNode()->generationInNode() != nullptr){
            System* s_2nd = findNextDPTerminal()->installNode()->generationInNode();
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
    _firstZ = std::numeric_limits<double>::quiet_NaN();
    _firstT = std::numeric_limits<double>::quiet_NaN();
    _secondZ = std::numeric_limits<double>::quiet_NaN();
    _secondT = std::numeric_limits<double>::quiet_NaN();
    _thirdZ = std::numeric_limits<double>::quiet_NaN();
    _thirdT = std::numeric_limits<double>::quiet_NaN();
}
