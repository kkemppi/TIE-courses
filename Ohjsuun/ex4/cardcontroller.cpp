#include "cardcontroller.hh"
#include "cardmodel.hh"
#include "cardmodel.hh"
#include <QRandomGenerator>
#include <QDebug>


const std::vector<QString> CardController::SMALL_CARDS = {"2", "3", "4", "5", "6", "7"};
const std::vector<QString> CardController::BIG_CARDS = {"9", "10", "J", "Q", "K", "A"};
const std::vector<QString> CardController::CARDS = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
const size_t CardController::POSSIBLE_CARD_VALUE_COUNT = CARDS.size();

CardController::CardController(CardModel *model, QObject *parent) :
    QObject(parent),
    cardModel_(model)
{
}

void CardController::generateCardValue()
{
    #if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
        unsigned long index = QRandomGenerator::global()->bounded(static_cast<int>(POSSIBLE_CARD_VALUE_COUNT));
    #else
        unsigned long index = static_cast<unsigned long>(qrand() % static_cast<int>(POSSIBLE_CARD_VALUE_COUNT));
    #endif
    cardModel_->setCardValue(CARDS.at(index));

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
            cardModel_->setCorrect(true);
            cardModel_->setCorrectAnswers(cardModel_->getCorrectAnswers()+1);
        }
        else
        {
            cardModel_->setCorrect(false);
            cardModel_->setIncorrectAnswers(cardModel_->getIncorrectAnswers()+1);
        }
    }
}


void CardController::resetPoints()
{
    cardModel_->setCorrectAnswers(0);
    cardModel_->setIncorrectAnswers(0);
}

CardController::CardSize CardController::getCardSize() const
{
    if (std::find(BIG_CARDS.begin(), BIG_CARDS.end(), cardModel_->getCardValue()) != BIG_CARDS.end())
    {
        return CardSize::BIG;
    }
    else if (std::find(SMALL_CARDS.begin(), SMALL_CARDS.end(), cardModel_->getCardValue()) != SMALL_CARDS.end())
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
