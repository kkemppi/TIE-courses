#include "logic.h"
#include <QRandomGenerator>
#include <QDebug>

Logic::Logic(QObject *parent) : QObject(parent)
{
    setCurrentValue(1234);
}

void Logic::setCurrentValue(int seed) {
    m_currentValue = qrand()%12+2;
}

bool Logic::checkSmall()
{
    if (m_currentValue <= 7) {
        return true;
    }else{
        return false;
    }
}

bool Logic::checkBig()
{
    if (m_currentValue > 7) {
        return true;
    }else{
        return false;
    }
}

int Logic::currentValue() {
    return m_currentValue;
}





