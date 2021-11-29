#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard")); // to enable virtualKeyboard

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

//#include <QGuiApplication>
//#include "window.h"

//int main(int argc, char *argv[])
//{
//  QGuiApplication app(argc, argv);

//  // Set OpenGL Version information
//  // Note: This format must be set before show() is called.
//  QSurfaceFormat format;
//  format.setRenderableType(QSurfaceFormat::OpenGL);
//  format.setProfile(QSurfaceFormat::CoreProfile);
//  format.setVersion(3,3);

//  // Set the window up
//  Window window;
//  window.setFormat(format);
//  window.resize(QSize(800, 600));
//  window.show();

//  return app.exec();
//}
