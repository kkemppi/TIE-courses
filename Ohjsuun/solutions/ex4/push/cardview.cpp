#include "cardview.hh"

CardView::CardView(QObject* parent) :
    QObject{ parent },
    cardValue_{ "" },
    correctGuess_{ false },
    correctAnswers_{ 0 },
    incorrectAnswers_{ 0 }
{
}

QString CardView::getCardValue() const
{
    return cardValue_;
}

bool CardView::isGuessCorrect() const
{
    return correctGuess_;
}

int CardView::getCorrectAnswers() const
{
    return correctAnswers_;
}

int CardView::getIncorrectAnswers() const
{
    return incorrectAnswers_;
}

void CardView::setCardValue(const QString& newValue)
{
    cardValue_ = newValue;
    emit cardValueChanged();
}

void CardView::setGuessCorrect(bool correctGuess)
{
    correctGuess_ = correctGuess;
    emit guessResultChanged();
}

void CardView::setCorrectAnswers(int correctAnswers)
{
    correctAnswers_ = correctAnswers;
    emit correctAnswersChanged();
}

void CardView::setIncorrectAnswers(int incorrectAnswers)
{
    incorrectAnswers_ = incorrectAnswers;
    emit incorrectAnswersChanged();
}
