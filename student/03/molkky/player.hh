#ifndef PLAYER_HH
#define PLAYER_HH
#include <string>
using namespace std;

class Player
{
public:
    Player(string name);
    string get_name() const;
    int get_points();
    bool has_won();
    void add_points(int pts);
    int points_;
private:
    string name_;
};

#endif // PLAYER_HH
