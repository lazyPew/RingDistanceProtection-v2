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
    const QRegExp rx(QLatin1Literal("[^0-9]+"));
    const auto&& parts = index().split(rx, QString::SkipEmptyParts);
    setFullName("ВЛ " + parts[0]);
}

WLine::WLine(QString csvLine, QObject *parent)
    : WLine(csvLine.split(";")[0],
            csvLine.split(";")[1].toDouble(),
            csvLine.split(";")[2].toDouble(),
            csvLine.split(";")[3].toDouble(),
            parent)
{
    setNodes(csvLine.split(";")[4],csvLine.split(";")[5]);
}

void WLine::setNodes(QString node1, QString node2)
{
    //TODO fix node setter
    if(node1 != _node_1)
        _node_1 = node1;
    if(node2 != _node_2)
        _node_2 = node2;
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
