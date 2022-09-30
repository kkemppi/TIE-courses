#include "cardview.hh"
#include "cardmodel.hh"

CardView::CardView(std::shared_ptr<CardModel> model,
                   QObject* parent) :
    QObject{ parent },
    model_{ model }
{
}

// NOTE: no nullptr checks for model_ at all here!

QString CardView::getCardValue() const
{
    return model_->getCardValue();
}

bool CardView::isGuessCorrect() const
{
    return model_->isCorrect();
}

int CardView::getCorrectAnswers() const
{
    return model_->getCorrectAnswers();
}

int CardView::getIncorrectAnswers() const
{
    return model_->getIncorrectAnswers();
}

void CardView::newCardValueGenerated()
{
    emit cardValueChanged();
}

void CardView::newGuessMade()
{
    if (model_->isCorrect())
    {
        emit correctAnswersChanged();
    }
    else
    {
        emit incorrectAnswersChanged();
    }
    emit guessResultChanged();
}

void CardView::pointsReseted()
{
    emit correctAnswersChanged();
    emit incorrectAnswersChanged();
}
