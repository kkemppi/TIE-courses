#ifndef CARDCONTROLLER_H
#define CARDCONTROLLER_H

#include <vector>
#include <QObject>

class CardController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString cardValue READ getCardValue NOTIFY cardValueChanged)
    Q_PROPERTY(int correctAnswers READ getCorrectAnswers NOTIFY correctAnswersChanged)
    Q_PROPERTY(int incorrectAnswers READ getIncorrectAnswers NOTIFY incorrectAnswersChanged)
    Q_PROPERTY(bool correct READ isCorrect NOTIFY choiceChanged)

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

    explicit CardController(QObject *parent = nullptr);

    QString getCardValue() const;

    Q_INVOKABLE void generateCardValue();
    Q_INVOKABLE void setCardChoice(const QString &choice);
    Q_INVOKABLE void resetPoints();

    int getCorrectAnswers() const;
    int getIncorrectAnswers() const;
    bool isCorrect() const;

    static const size_t POSSIBLE_CARD_VALUE_COUNT;
    static const std::vector<QString> SMALL_CARDS;
    static const std::vector<QString> BIG_CARDS;
    static const std::vector<QString> CARDS;

signals:
    void cardValueChanged();
    void correctAnswersChanged();
    void incorrectAnswersChanged();
    void choiceChanged();

private:
    CardSize getCardSize() const;
    PlayerChoice getPlayerChoice(const QString &playerChoice);

    QString cardValue_;
    bool correctChoice_;
    int correctAnswers_;
    int incorrectAnswers_;
};

#endif // CARDCONTROLLER_H
