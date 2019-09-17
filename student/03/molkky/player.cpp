#include "player.hh"
using  namespace std;


Player::Player(string name):
    name_(name){

}

string Player::get_name() const {
    return name_;
}

int Player::get_points()    {
    return points_;
}

bool Player::has_won()  {
    if (points_ == 50) {
        return true;
    }
    else {
        return false;
    }
}

void Player::add_points(int pts) {
    if (points_ + pts <= 50) {
        points_ = points_ + pts;
    }
    else {
        points_ = 25;
    }
}
