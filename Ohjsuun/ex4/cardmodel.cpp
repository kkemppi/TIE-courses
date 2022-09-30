#include "cardmodel.hh"

#include <algorithm>
#include <QDebug>


CardModel::CardModel(QObject *parent) :
    QObject(parent),
    m_cardValue{},
    m_correctAnswers{0},
    m_incorrectAnswers{0},
    m_correct{false}
{

}

void CardModel::setCorrectAnswers(int correctAnswers)
{
    if (m_correctAnswers == correctAnswers)
        return;

    m_correctAnswers = correctAnswers;
    emit correctAnswersChanged(m_correctAnswers);
}

void CardModel::setIncorrectAnswers(int incorrectAnswers)
{
    if (m_incorrectAnswers == incorrectAnswers)
        return;

    m_incorrectAnswers = incorrectAnswers;
    emit incorrectAnswersChanged(m_incorrectAnswers);
}

void CardModel::setCorrect(bool correct)
{
    if (m_correct == correct)
        return;

    m_correct = correct;
    emit choiceChanged(m_correct);
}

void CardModel::setCardValue(QString cardValue)
{
    if (m_cardValue == cardValue)
        return;

    m_cardValue = cardValue;
    emit cardValueChanged(m_cardValue);
}


QString CardModel::getCardValue() const
{

    return m_cardValue;
}


int CardModel::getCorrectAnswers() const
{
    return m_correctAnswers;
}

int CardModel::getIncorrectAnswers() const
{
    return m_incorrectAnswers;
}

bool CardModel::isCorrect() const
{
    return m_correct;
}
