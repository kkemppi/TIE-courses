#ifndef CARDCONTROLLER_HH
#define CARDCONTROLLER_HH

#include <memory>
#include <QObject>

class CardModel;

class CardController : public QObject
{
    Q_OBJECT

public:
    explicit CardController(std::shared_ptr<CardModel> model,
                            QObject* parent = nullptr);

    Q_INVOKABLE void generateNewCardValue();
    Q_INVOKABLE void makeGuess(const QString& guess);
    Q_INVOKABLE void resetPoints();

private:
    std::shared_ptr<CardModel> model_;
};

#endif // CARDCONTROLLER_HH
