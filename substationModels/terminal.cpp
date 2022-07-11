#include "terminal.h"
#include <QQmlEngine>

Terminal::Terminal(QString name,
//                   Function* func,
                   QObject *parent)
    : QObject(parent)
    , _name{name}
//    , _function{func}
{
    registerQmlTypes();
}

Terminal::Terminal(QString name,
                   ProtectedEquipment* protectedEquipment,
//                   Function* func,
                   QObject *parent)
    : QObject(parent)
//    : Terminal(name,/*func,*/parent)
    , _name{name}
//    , _function{func}
    , _protectedEquipment{protectedEquipment}
{
    registerQmlTypes();
}

void Terminal::registerQmlTypes() {
    static bool registered = false;
    if (!registered) {
        qmlRegisterUncreatableType<Terminal>(
                    "DataModelTypes", 1, 0,
                    "Terminal", "NOPE"
                    );
//        qRegisterMetaType<Error>("Error");
//        qRegisterMetaType<FeedbackState>("FeedbackState");
        registered = true;
    }
}
