#include "cardmodel.hh"
#include "cardview.hh"
#include <algorithm>

// use the preprocessor directives to support older versions of Qt with the random number generation
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
    #include <QRandomGenerator>
#else
    #include <QDateTime>
#endif

const std::vector<QString> CardModel::SMALL_CARDS = { "2", "3", "4", "5", "6", "7" };
const std::vector<QString> CardModel::BIG_CARDS = { "9", "10", "J", "Q", "K", "A" };
const std::vector<QString> CardModel::CARDS = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
const size_t CardModel::POSSIBLE_CARD_VALUE_COUNT = CARDS.size();

CardModel::CardModel() :
    view_{ nullptr },
    cardValue_{ CARDS[0] },
    correctChoice_{ false },
    correctAnswers_{ 0 },
    incorrectAnswers_{ 0 }
{
    // for Qt version 5.9 or earlier, setup the seed for the random number generator using the current time
    #if (QT_VERSION < QT_VERSION_CHECK(5, 10, 0))
        uint currentTime = QDateTime::currentDateTime().toTime_t();
        qsrand(currentTime);
    #endif
}

void CardModel::setView(std::shared_ptr<CardView> view)
{
    view_ = view;
}

QString CardModel::getCardValue() const
{
    return cardValue_;
}

bool CardModel::isCorrect() const
{
    return correctChoice_;
}

int CardModel::getCorrectAnswers() const
{
    return correctAnswers_;
}

int CardModel::getIncorrectAnswers() const
{
    return incorrectAnswers_;
}

void CardModel::generateCardValue()
{
    #if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
        unsigned long index = QRandomGenerator::global()->bounded(static_cast<int>(POSSIBLE_CARD_VALUE_COUNT));
    #else
        unsigned long index = static_cast<unsigned long>(qrand() % static_cast<int>(POSSIBLE_CARD_VALUE_COUNT));
    #endif
    cardValue_ = CARDS.at(index);

    if (view_ != nullptr)
    {
        view_->newCardValueGenerated();
    }
}

void CardModel::setCardChoice(const QString& choice)
{
    PlayerChoice playerChoice = getPlayerChoice(choice);
    if (playerChoice == PlayerChoice::SMALL || playerChoice == PlayerChoice::BIG)
    {
        CardSize cardSize = getCardSize();
        correctChoice_ = (
            (cardSize == CardSize::SMALL && playerChoice == PlayerChoice::SMALL) ||
            (cardSize == CardSize::BIG && playerChoice == PlayerChoice::BIG)
        );

        if (correctChoice_)
        {
            ++correctAnswers_;
        }
        else
        {
            ++incorrectAnswers_;
        }

        if (view_ != nullptr)
        {
            view_->newGuessMade();
        }
    }
}

void CardModel::resetPoints()
{
    correctAnswers_ = 0;
    incorrectAnswers_ = 0;

    if (view_ != nullptr)
    {
        view_->pointsReseted();
    }
}

CardModel::CardSize CardModel::getCardSize() const
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

CardModel::PlayerChoice CardModel::getPlayerChoice(const QString &playerChoice)
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
