#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>            // needed for setContextProperty
//#include <QQmlEngine>           // needed for qmlRegisterType
#include "cardcontroller.hh"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // sharing the created CardController object to the QML with setContextProperty
    CardController cardController;
    engine.rootContext()->setContextProperty("cardController", &cardController);

    // example on how to register CardController as a new QML element
    // note, that the QML_ELEMENT macro used in the documentation is only available for Qt 5.15
//    qmlRegisterType<CardController>("cardController", 0, 2, "CardController");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
