#include "cardcontroller.hh"
#include "cardmodel.hh"
#include "cardview.hh"

CardController::CardController(std::shared_ptr<CardModel> model,
                               std::shared_ptr<CardView> view,
                               QObject* parent) :
    QObject{ parent },
    model_{ model },
    view_{ view }
{
}

// NOTE: no nullptr checks for model_ or view_ at all here!

void CardController::generateNewCardValue()
{
    model_->generateCardValue();
    view_->newCardValueGenerated();
}

void CardController::makeGuess(const QString& guess)
{
    model_->setCardChoice(guess);
    view_->newGuessMade();
}

void CardController::resetPoints()
{
    model_->resetPoints();
    view_->pointsReseted();
}
