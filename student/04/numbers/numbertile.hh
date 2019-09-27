/* Class: Numbertile
 *
 * Acts as a single tile in the board.
 *
 * Name: Mikko Kemppi & Olli-Pekka Pettersson
 * Student number: 272670 & 283651
 * UserID: kemppim & pertterso
 * E-Mail: mikko.kemppi@tuni.fi & olli.pettersson@tuni.fi
 *
 *
 * */
#ifndef NUMBERTILE_HH
#define NUMBERTILE_HH
#include <utility>
#include <vector>

class NumberTile
{
public:
    // Public part contains variables and methods that can be used outside the
    // class itself.

    // Constructor that takes in a value, a location and the board the tile is on.
    NumberTile(int value, std::pair<int, int> coords,
               std::vector<std::vector<NumberTile> > *board);

    // Prints the tile in the desired width.
    void print( int width );

    // Tries to set a new value to the tile. Returns true if successful, false
    // if the tile already contains some value.
    bool setValue(int value, bool new_value=false);

    int getValue();

private:
    // Private part contains variables and methods that shouldn't be usable
    // outside the class.

    // Value of the tile.
    int value_;

    // Developer notes: These were not used and are just to get rid of issues
    std::pair<int, int> coords_;
    std::vector<std::vector<NumberTile>> *board_;
};

#endif // NUMBERTILE_HH
