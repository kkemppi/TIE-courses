#include "cardcontroller.hh"
#include "cardmodel.hh"

CardController::CardController(std::shared_ptr<CardModel> model,
                               QObject* parent) :
    QObject{ parent },
    model_{ model }
{
}

// NOTE: no nullptr checks for model_ at all here!

void CardController::generateNewCardValue()
{
    model_->generateCardValue();
}

void CardController::makeGuess(const QString& guess)
{
    model_->setCardChoice(guess);
}

void CardController::resetPoints()
{
    model_->resetPoints();
}
