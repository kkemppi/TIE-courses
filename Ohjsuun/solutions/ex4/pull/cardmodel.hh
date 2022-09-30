#ifndef CARDMODEL_HH
#define CARDMODEL_HH

#include <memory>
#include <QString>
#include <vector>

class CardView;

class CardModel
{

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

    CardModel();
    void setView(std::shared_ptr<CardView> view);

    QString getCardValue() const;
    bool isCorrect() const;
    int getCorrectAnswers() const;
    int getIncorrectAnswers() const;

    void generateCardValue();
    void setCardChoice(const QString& choice);
    void resetPoints();

private:
    std::shared_ptr<CardView> view_;
    QString cardValue_;
    bool correctChoice_;
    int correctAnswers_;
    int incorrectAnswers_;

    static const size_t POSSIBLE_CARD_VALUE_COUNT;
    static const std::vector<QString> SMALL_CARDS;
    static const std::vector<QString> BIG_CARDS;
    static const std::vector<QString> CARDS;

    CardSize getCardSize() const;
    PlayerChoice getPlayerChoice(const QString &playerChoice);
};

#endif // CARDMODEL_HH
