#include "cardmodel.hh"
#include "cardcontroller.hh"
#include "cardview.hh"
#include <memory>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // setup the dependencies required by the push MCV model
    auto cardView{ std::make_shared<CardView>() };
    auto cardModel{ std::make_shared<CardModel>(cardView) };
    auto cardController{ std::make_shared<CardController>(cardModel) };

    // give the QML side acces to the view and controller components
    auto context{ engine.rootContext() };
    context->setContextProperty("cardView", cardView.get());
    context->setContextProperty("cardController", cardController.get());

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
