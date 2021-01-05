#ifndef CHARACTER_H
#define CHARACTER_H

#include <QGraphicsPixmapItem>
#include "bomb.h"
#include <QObject>

/**
 *@file
 * @brief Defines a class for playable characer
 */

//constants for checking wallhit
const int HX_MIN = -165;
const int HX_MAX = 905;
const int HY_MIN = -165;
const int HY_MAX = 370;

namespace Students {
class Character : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Character();
    void move();
    int direction() const;
    void setDirection(int);
    /**
     * @brief emits damage_recieved
     */
    void crash();
    /**
     * @brief sets helicopter picture for every move so helicopter seems like it's flying
     */
    void rotorPhase();
    /**
     * @brief bomb is dropped
     * @return pointer to dropped bomb
     */
    Bomb* dropBomb();
    /**
     * @brief check if helicopter hits edge of map
     */
    void wallhit();
    /**
     * @brief helicopter gets upgraded to apache helicopter
     */
    void transfrom();
    int getType() const;

signals:
    /**
     * @brief damage signal will be emitted to bettermainwindow slot damage_taken
     */
    void damage_recieved();

private:
    int direction_;
    //determines what helicoptergraphic is shown
    int phase_ = 1;
    //determines if helicopter is normal (1) or apache (2)
    int type_ = 1;
    double speed_ = 1;
};
}


#endif // CHARACTER_H
