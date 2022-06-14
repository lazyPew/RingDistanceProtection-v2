#ifndef DISTANCEPROTECTION_H
#define DISTANCEPROTECTION_H

#include "terminal.h"
#include "connectivitynode.h"

class DistanceProtectionTerminal : public Terminal
{
    Q_OBJECT
public:
    explicit DistanceProtectionTerminal(QString csvLine, QObject* parent = nullptr);
    explicit DistanceProtectionTerminal(QString name,
                                        WLine* protectionObject,
                                        QObject* parent = nullptr);
    explicit DistanceProtectionTerminal(QString name,
                                        WLine* protectionObject,
                                        ConnectivityNode* installNode,
                                        ConnectivityNode* directionNode,
                                        QObject* parent = nullptr);

    void connectToNodes(ConnectivityNode* installNode,
                        ConnectivityNode* directionNode);

public slots:
    void calculateParameters();

    WLine* protectedEquipmentAsWLine();

private:
    void resetParameters();

    void calculateFirstStep_DP();
    void calculateSecondStep_DP();
    void calculateThirdStep_DP();

//    DistanceProtectionTerminal* findNextDPTerminal();
private:
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
