/*  Source file for NumberTile class.
 *
 * Also contains an operator for pair addition.
 *
 * Name: Mikko Kemppi & Olli-Pekka Pettersson
 * Student number: 272670 & 283651
 * UserID: kemppim & pertterso
 * E-Mail: mikko.kemppi@tuni.fi & olli.pettersson@tuni.fi
 */
#include "numbertile.hh"
#include <iomanip>
#include <iostream>

// Pair addition operator. Allows to do result_pair = pair_1 + pair_2
// Developer notes: This was not actually used, could have been useful
std::pair<int, int>operator +(std::pair<int, int> lhs, std::pair<int, int> rhs){
    return std::make_pair(lhs.first + rhs.first, lhs.second + rhs.second);
}

NumberTile::NumberTile(int value,
                       std::pair<int, int> coords,
                       std::vector<std::vector<NumberTile>> *board)
    : value_(value), coords_(coords), board_(board)
{
}


void NumberTile::print(int width)
{
    // std::setw() sets the width of next printable to given amount, usually
    // by adding spaces in front.
    std::cout << "|" << std::setw(width - 1) << value_;
}

bool NumberTile::setValue(int value, bool new_value){
    // Add NEW_VALUE to a empty tile
    if (new_value) {
        if (value_ == 0){
            value_ = value;
            return true;
        }else{
            return false;
        }
    // Change value to given value
    }else{
        value_ = value;
    }
return 0;
}

int NumberTile::getValue(){
    return value_;
}

