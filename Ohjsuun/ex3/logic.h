#ifndef LOGIC_H
#define LOGIC_H

#include <QObject>

class Logic : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int currentValue READ currentValue WRITE setCurrentValue NOTIFY currentValueChanged)
public:
    explicit Logic(QObject *parent = nullptr);

    void setCurrentValue(int seed);

    Q_INVOKABLE bool checkSmall();
    Q_INVOKABLE bool checkBig();

    int currentValue();

signals:
    void currentValueChanged();
private:
    int m_currentValue;

};

#endif // LOGIC_H
