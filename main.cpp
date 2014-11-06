#include <QApplication>
#include <QQmlApplicationEngine>
#include "testhttps.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    TestHTTPS* testhttps = new TestHTTPS();
    testhttps->get();

    return app.exec();
}
