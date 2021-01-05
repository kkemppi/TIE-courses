#ifndef OddBall_HH
#define OddBall_HH

#include "movingobject.hh"


class OddBall : public MovingObject
{
public:
    OddBall();

    void move() final;

private:
    int speed_;
    int dir_x_;
    int dir_y_;
};

#endif // OddBall_HH
