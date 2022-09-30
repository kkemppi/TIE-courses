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

    // setup the dependencies required by the pull MCV model
    auto cardModel{ std::make_shared<CardModel>() };
    auto cardView{ std::make_shared<CardView>(cardModel) };
    auto cardController{ std::make_shared<CardController>(cardModel) };
    // since the dependencies form a circle, one of them needs to be set outside of a constructor
    cardModel->setView(cardView);

    // give the QML side acces to the view and controller components
    auto context{ engine.rootContext() };
    context->setContextProperty("cardView", cardView.get());
    context->setContextProperty("cardController", cardController.get());

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
