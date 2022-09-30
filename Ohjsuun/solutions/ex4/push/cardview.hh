#ifndef CARDVIEW_HH
#define CARDVIEW_HH

#include <memory>
#include <QObject>
#include <QString>

class CardView : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString cardValue READ getCardValue WRITE setCardValue NOTIFY cardValueChanged)
    Q_PROPERTY(bool guessCorrect READ isGuessCorrect WRITE setGuessCorrect NOTIFY guessResultChanged)
    Q_PROPERTY(int correctAnswers READ getCorrectAnswers WRITE setCorrectAnswers NOTIFY correctAnswersChanged)
    Q_PROPERTY(int incorrectAnswers READ getIncorrectAnswers WRITE setIncorrectAnswers NOTIFY incorrectAnswersChanged)

public:
    explicit CardView(QObject* parent = nullptr);

    QString getCardValue() const;
    bool isGuessCorrect() const;
    int getCorrectAnswers() const;
    int getIncorrectAnswers() const;

    void setCardValue(const QString& newValue);
    void setGuessCorrect(bool correctGuess);
    void setCorrectAnswers(int correctAnswers);
    void setIncorrectAnswers(int incorrectAnswers);

signals:
    void cardValueChanged();
    void guessResultChanged();
    void correctAnswersChanged();
    void incorrectAnswersChanged();

private:
    // with the push MVC, the component that communicates the values to the QML side,
    // must have the actual values (because the view has no information about the model),
    // so they are also stored here
    QString cardValue_;
    bool correctGuess_;
    int correctAnswers_;
    int incorrectAnswers_;
};

#endif // CARDVIEW_HH
