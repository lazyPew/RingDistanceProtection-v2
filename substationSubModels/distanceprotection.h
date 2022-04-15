#ifndef DISTANCEPROTECTION_H
#define DISTANCEPROTECTION_H

#include "terminal.h"
#include "connectivitynode.h"

class DistanceProtectionTerminal : public Terminal
{
    Q_OBJECT
public:
    DistanceProtectionTerminal(QObject* parent = nullptr);

private:
    // protectionObject ???
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
