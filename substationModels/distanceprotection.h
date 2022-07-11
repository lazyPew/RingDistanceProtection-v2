#ifndef DISTANCEPROTECTION_H
#define DISTANCEPROTECTION_H

#include "terminal.h"
#include "function.h"
#include "connectivitynode.h"

class DistanceProtectionTerminal : public Terminal
{
    Q_OBJECT

    Q_PROPERTY(double firstZ
               READ firstZ
               CONSTANT)
    Q_PROPERTY(double firstT
               READ firstT
               CONSTANT)

    Q_PROPERTY(double secondZ
               READ secondZ
               CONSTANT)
    Q_PROPERTY(double secondT
               READ secondT
               CONSTANT)

    Q_PROPERTY(double thirdZ
               READ thirdZ
               CONSTANT)
    Q_PROPERTY(double thirdT
               READ thirdT
               CONSTANT)

public:
    explicit DistanceProtectionTerminal(QString csvLine,
                                        Function* parentModel,
                                        QObject* parent = nullptr);
    explicit DistanceProtectionTerminal(QString name,
                                        WLine* protectionObject,
                                        Function* parentModel,
                                        QObject* parent = nullptr);
    explicit DistanceProtectionTerminal(QString name,
                                        WLine* protectionObject,
                                        ConnectivityNode* installNode,
                                        ConnectivityNode* directionNode,
                                        Function* parentModel,
                                        QObject* parent = nullptr);

    void connectToNodes(ConnectivityNode* installNode,
                        ConnectivityNode* directionNode);

    void firstStepCalculation()     { calculateFirstStep_DP(); }
    void secondStepCalculation()    { calculateSecondStep_DP(); }
    void thirdStepCalculation()     { calculateThirdStep_DP(); }

public slots:
    void calculateParameters();
    QString getResults();

    ConnectivityNode* installNode() const   { return _installNode; }
    ConnectivityNode* directionNode() const { return _directionNode; }

    double firstZ() const   { return _firstZ; }
    double secondZ() const  { return _secondZ; }
    double thirdZ() const   { return _thirdZ; }

    double firstT() const   { return _firstT; }
    double secondT() const  { return _secondT; }
    double thirdT() const   { return _thirdT; }


private:
    void resetParameters();

    void calculateFirstStep_DP();
    void calculateSecondStep_DP();
    void calculateThirdStep_DP();

    double infeedCoef();
    System* generationFromBehind();
    WLine* protectedEquipmentAsWLine();
    DistanceProtectionTerminal* findNextDPTerminal();
    Transformer* chooseTransformer(DistanceProtectionTerminal*);

private:
    Function* _function;
//    WLine* _protectionObject;
    ConnectivityNode* _installNode;
    ConnectivityNode* _directionNode;

    double _firstZ;
    double _secondZ;
    double _thirdZ;

    double _firstT;
    double _secondT;
    double _thirdT;
};
#endif // DISTANCEPROTECTION_H
