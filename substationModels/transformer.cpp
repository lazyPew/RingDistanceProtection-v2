#include "transformer.h"

Transformer::Transformer(QObject *parent) : QObject(parent)
{

}

Transformer::Transformer(QString csvLine, QObject *parent)
    : QObject(parent)
    , _name {csvLine.split(";")[0]}
    , _powerS {csvLine.split(";")[1].toDouble()}
    , _hvLevel{csvLine.split(";")[2].toInt()}
    , _mvLevel{csvLine.split(";")[3].toInt()}
    , _lvLevel{csvLine.split(";")[4].toInt()}
    , _uKoefH_L{csvLine.split(";")[5].toDouble()}
    , _uKoefH_M{csvLine.split(";")[6].toDouble()}
    , _uKoefM_L{csvLine.split(";")[7].toDouble()}
    , _regulation{csvLine.split(";")[8].toDouble()}
{}
