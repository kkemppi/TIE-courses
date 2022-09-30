#ifndef CARDCONTROLLER_HH
#define CARDCONTROLLER_HH

#include <QObject>
#include "cardmodel.hh"

class CardController : public QObject
{
    Q_OBJECT
public:
    enum class CardSize {
        SMALL,
        BIG,
        UNDEFINED
    };

    enum class PlayerChoice {
        SMALL,
        BIG,
        UNKNOWN
    };
    explicit CardController(CardModel *model = nullptr, QObject *parent = nullptr);

    Q_INVOKABLE void generateCardValue();
    Q_INVOKABLE void setCardChoice(const QString &choice);
    Q_INVOKABLE void resetPoints();

signals:
    void cardValueChanged();
    void correctAnswersChanged();
    void incorrectAnswersChanged();
    void choiceChanged();

private:
    CardModel *cardModel_;

    PlayerChoice getPlayerChoice(const QString &playerChoice);
    CardSize getCardSize() const;

    static const size_t POSSIBLE_CARD_VALUE_COUNT;
    static const std::vector<QString> SMALL_CARDS;
    static const std::vector<QString> BIG_CARDS;
    static const std::vector<QString> CARDS;

};

#endif // CARDCONTROLLER_HH
