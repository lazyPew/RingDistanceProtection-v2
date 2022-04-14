#include <QGuiApplication>
#include <QQmlApplicationEngine>
//#include <QtQml>
//#include <QJSEngine>

#include "controlpanel.h"

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard")); // to enable virtualKeyboard

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

//    QJSEngine scriptEngine;

//    QJSValue appInfo = scriptEngine.newObject();
//    appInfo.setProperty("version", GIT_VERSION);

    ControlPanel panel;

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
