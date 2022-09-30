#ifndef CARDMODEL_HH
#define CARDMODEL_HH

#include <vector>
#include <QObject>

class CardModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString cardValue READ getCardValue WRITE setCardValue NOTIFY cardValueChanged)
    Q_PROPERTY(int correctAnswers READ getCorrectAnswers WRITE setCorrectAnswers NOTIFY correctAnswersChanged)
    Q_PROPERTY(int incorrectAnswers READ getIncorrectAnswers WRITE setIncorrectAnswers NOTIFY incorrectAnswersChanged)
    Q_PROPERTY(bool correct READ isCorrect WRITE setCorrect NOTIFY choiceChanged)

public:


    explicit CardModel(QObject *parent = nullptr);

    QString getCardValue() const;
    int getCorrectAnswers() const;
    int getIncorrectAnswers() const;
    bool isCorrect() const;

    void setCardChoice(const QString &choice);

public slots:
    void setCorrectAnswers(int correctAnswers);

    void setIncorrectAnswers(int incorrectAnswers);

    void setCorrect(bool correct);

    void setCardValue(QString cardValue);

signals:
    void cardValueChanged(QString cardValue);

    void correctAnswersChanged(int correctAnswers);

    void incorrectAnswersChanged(int incorrectAnswers);

    void choiceChanged(bool correct);

private:
    QString m_cardValue;
    int m_correctAnswers;
    int m_incorrectAnswers;
    bool m_correct;
};

#endif // CARDMODEL_HH
