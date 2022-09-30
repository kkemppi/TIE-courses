#include "cardcontroller.hh"

#include <algorithm>
#include <QtGlobal>

// use the preprocessor directives to support older versions of Qt with the random number generation
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
    #include <QRandomGenerator>
#else
    #include <QDateTime>
#endif

const std::vector<QString> CardController::SMALL_CARDS = {"2", "3", "4", "5", "6", "7"};
const std::vector<QString> CardController::BIG_CARDS = {"9", "10", "J", "Q", "K", "A"};
const std::vector<QString> CardController::CARDS = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
const size_t CardController::POSSIBLE_CARD_VALUE_COUNT = CardController::CARDS.size();

CardController::CardController(QObject *parent) :
    QObject(parent),
    cardValue_{CARDS[0]},
    correctChoice_{false},
    correctAnswers_{0},
    incorrectAnswers_{0}
{
    // for Qt version 5.9 or earlier, setup the seed for the random number generator using the current time
    #if (QT_VERSION < QT_VERSION_CHECK(5, 10, 0))
        uint currentTime = QDateTime::currentDateTime().toTime_t();
        qsrand(currentTime);
    #endif
}

QString CardController::getCardValue() const
{
    return cardValue_;
}

void CardController::generateCardValue()
{
    #if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
        unsigned long index = QRandomGenerator::global()->bounded(static_cast<int>(POSSIBLE_CARD_VALUE_COUNT));
    #else
        unsigned long index = static_cast<unsigned long>(qrand() % static_cast<int>(POSSIBLE_CARD_VALUE_COUNT));
    #endif
    cardValue_ = CARDS.at(index);

    emit cardValueChanged();
}

void CardController::setCardChoice(const QString &choice)
{
    PlayerChoice playerChoice = getPlayerChoice(choice);

    if (playerChoice == PlayerChoice::SMALL || playerChoice == PlayerChoice::BIG)
    {
        CardSize cardSize = getCardSize();
        if ((cardSize == CardSize::SMALL && playerChoice == PlayerChoice::SMALL) ||
            (cardSize == CardSize::BIG && playerChoice == PlayerChoice::BIG))
        {
            correctChoice_ = true;
            ++correctAnswers_;
            emit correctAnswersChanged();
        }
        else
        {
            correctChoice_ = false;
            ++incorrectAnswers_;
            emit incorrectAnswersChanged();
        }
        emit choiceChanged();
    }
}

void CardController::resetPoints()
{
    correctAnswers_ = 0;
    emit correctAnswersChanged();

    incorrectAnswers_ = 0;
    emit incorrectAnswersChanged();
}

int CardController::getCorrectAnswers() const
{
    return correctAnswers_;
}

int CardController::getIncorrectAnswers() const
{
    return incorrectAnswers_;
}

bool CardController::isCorrect() const
{
    return correctChoice_;
}

CardController::CardSize CardController::getCardSize() const
{
    if (std::find(BIG_CARDS.begin(), BIG_CARDS.end(), cardValue_) != BIG_CARDS.end())
    {
        return CardSize::BIG;
    }
    else if (std::find(SMALL_CARDS.begin(), SMALL_CARDS.end(), cardValue_) != SMALL_CARDS.end())
    {
        return CardSize::SMALL;
    }
    else
    {
        return CardSize::UNDEFINED;
    }
}

CardController::PlayerChoice CardController::getPlayerChoice(const QString &playerChoice)
{
    QString playerChoiceUpper = playerChoice.toUpper();
    if (playerChoiceUpper == "SMALL")
    {
        return PlayerChoice::SMALL;
    }
    else if (playerChoiceUpper == "BIG")
    {
        return PlayerChoice::BIG;
    }
    else
    {
        return PlayerChoice::UNKNOWN;
    }
}
