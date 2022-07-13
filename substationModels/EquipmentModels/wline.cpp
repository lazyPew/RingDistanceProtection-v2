#include "wline.h"

WLine::WLine(QString name,
             double length,
             double resistX,
             double resistR,
             QObject *parent)
    : ProtectedEquipment (name, parent)
    , _length{length}
    , _resistX{resistX}
    , _resistR{resistR}
{

}

WLine::WLine(QString csvLine, QObject *parent)
    : ProtectedEquipment(csvLine.split(";")[0],parent)
    , _length {csvLine.split(";")[1].toDouble()}
    , _resistX {csvLine.split(";")[2].toDouble()}
    , _resistR {csvLine.split(";")[3].toDouble()}
    , _node_1{csvLine.split(";")[4]}
    , _node_2{csvLine.split(";")[5]}
{

}

//void WLine::registerQmlTypes() {
//    static bool registered = false;
//    if (!registered) {
//        qmlRegisterUncreatableType<DistanceProtectionTerminal>(
//                    "DataModelTypes", 1, 0,
//                    "Terminal", "NOPE"
//                    );
////        qRegisterMetaType<Error>("Error");
////        qRegisterMetaType<FeedbackState>("FeedbackState");
//        registered = true;
//    }
//}
