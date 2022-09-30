#ifndef CARDVIEW_HH
#define CARDVIEW_HH

#include <memory>
#include <QObject>

class CardModel;

class CardView : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString cardValue READ getCardValue NOTIFY cardValueChanged)
    Q_PROPERTY(bool guessCorrect READ isGuessCorrect NOTIFY guessResultChanged)
    Q_PROPERTY(int correctAnswers READ getCorrectAnswers NOTIFY correctAnswersChanged)
    Q_PROPERTY(int incorrectAnswers READ getIncorrectAnswers NOTIFY incorrectAnswersChanged)

public:
    explicit CardView(std::shared_ptr<CardModel> model,
                      QObject* parent = nullptr);

    QString getCardValue() const;
    bool isGuessCorrect() const;
    int getCorrectAnswers() const;
    int getIncorrectAnswers() const;

    // updates the value for the cardValue property from the model
    void newCardValueGenerated();
    // updates the values for guessCorrect, correctAnswers and incorrectAnswers properties from the model
    void newGuessMade();
    // updates the values for correctAnswers and incorrectAnswers properties from the model
    void pointsReseted();

signals:
    void cardValueChanged();
    void guessResultChanged();
    void correctAnswersChanged();
    void incorrectAnswersChanged();

private:
    std::shared_ptr<CardModel> model_;
};

#endif // CARDVIEW_HH
