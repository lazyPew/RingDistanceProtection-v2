#include "transformer.h"
#include <math.h>
#include <QDebug>
#include <QQmlEngine>

const QMap<QString,double> voltageMap = {
    {"110",115}
};

Transformer::Transformer(QString csvLine, QObject *parent)
    : ProtectedEquipment(csvLine.split(";")[0], parent)
    , _powerS    {csvLine.split(";")[1].toDouble()}
    , _hvLevel   {csvLine.split(";")[2].toInt()}
    , _mvLevel   {csvLine.split(";")[3].toInt()}
    , _lvLevel   {csvLine.split(";")[4].toInt()}
    , _uKoefH_M  {csvLine.split(";")[5].toDouble()}
    , _uKoefH_L  {csvLine.split(";")[6].toDouble()}
    , _uKoefM_L  {csvLine.split(";")[7].toDouble()}
    , _regulation{csvLine.split(";")[8].toDouble()}
    , _nodeHV    {csvLine.split(";")[9]}
    , _nodeMV    {csvLine.split(";")[10]}
    , _nodeLV    {csvLine.split(";")[11]}
{
    setFullName("ТДТН " + QString::number(int(_powerS) * 1000) +"/"+ voltageMap.key(_hvLevel));
    registerQmlTypes();
}

double Transformer::transformerImpedanceHV()
{
    double ukoefH = 0.5 * (_uKoefH_M + _uKoefH_L - _uKoefM_L);
    if (ukoefH <= 0)
        return 0;
    else
        return ((ukoefH / 100) * (pow(_hvLevel,2) / _powerS));
}
double Transformer::transformerImpedanceMV()
{
    double ukoefM = 0.5 * (_uKoefH_M + _uKoefM_L - _uKoefH_L);
    if (ukoefM <= 0)
        return 0;
    else
        return ((ukoefM / 100) * (pow(_hvLevel,2) / _powerS));
}
double Transformer::transformerImpedanceLV()
{
    double ukoefL = 0.5 * (_uKoefM_L + _uKoefH_L - _uKoefH_M);
    if (ukoefL <= 0)
        return 0;
    else
        return ((ukoefL / 100) * (pow(_hvLevel,2) / _powerS));
}

double Transformer::distanceProtectionHV()
{
    return 0.87 * transformerImpedanceHV();
}

void Transformer::registerQmlTypes() {
    static bool registered = false;
    if (!registered) {
        qmlRegisterUncreatableType<Transformer>(
                    "DataModelTypes", 1, 0,
                    "Transformer", "NOPE"
                    );
        registered = true;
    }
}
