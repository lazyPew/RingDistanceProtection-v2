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
};
#endif // DISTANCEPROTECTION_H
