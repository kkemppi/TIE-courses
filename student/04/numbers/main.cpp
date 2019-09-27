﻿/* Numbers ( or 2048, but that's an invalid name ) : Template code
 *
 * Desc:
 *  This program generates a game of 2048, a tile combining game
 * where the goal is to get from 2's to 2048. The board is SIZE x SIZE,
 * ( original was 4x4 ) and every round the player chooses a direction
 * to which the tiles should fall. If they collide with a wall or a different
 * value, they will move as close as they can get. If they collide with
 * a tile with same value, they will combine and double the value. The
 * tile will continue to move until a wall or other tile comes along, but a
 * single tile can only be combined once per "turn".
 *  Game will end when the goal value asked (orig 2048) is reached or new
 * tile can't be added to the board.
 *
 * Name: Mikko Kemppi & Olli-Pekka Pettersson
 * Student number: 272670 & 283651
 * UserID: kemppim & pertterso
 * E-Mail: mikko.kemppi@tuni.fi & olli.pettersson@tuni.fi
 *
 * Notes about the program and it's implementation:
 * */

#include "numbertile.hh"
#include <iostream>
#include <vector>
#include <random>
#include <string>

const int SIZE = 4;
const int NEW_VALUE = 2;
const int PRINT_WIDTH = 5;
const int DEFAULT_GOAL = 2048;


// Adds a single new value to board using rEng and distr for random positioning.
void newValue(std::vector<std::vector<NumberTile>> &board,
               std::default_random_engine &rEng,
               std::uniform_int_distribution<int> &distr){
    // Tries to assign NEW_VAl to randomly selected tile. Continues trying until
    // newVal() returns true.
    while(!board.at(distr(rEng)).at(distr(rEng)).setValue(NEW_VALUE, true));
}

// Initializes the board to size SIZE x SIZE and adds SIZE tiles with NEW_VALUE
// to it through new_value() func after initializing the random engine with
// a seed value.

bool is_int(std::string goal){
    try  {
        throw(std::stoi(goal));
    }
    catch (const std::invalid_argument&)  {
        return false;
    }
    catch (...){
        return true;
    }
}

int initBoard(std::vector<std::vector<NumberTile>> &board,
                std::default_random_engine &rEng,
                std::uniform_int_distribution<int> &distr){

    // Initialize the board with SIZE x SIZE empty numbertiles.
    for ( auto y = 0; y < SIZE; y++ ){
        board.push_back({});
        for ( auto x = 0; x < SIZE; x++ ){
            // If you don't want to use pairs, replace "std::make_pair(y, x)"
            // with "y, x".
            board.at(y).push_back(NumberTile(0, std::make_pair(y, x), &board));
        }

    }

    // Ask user for the seed value and initialize rEng.
    std::cout << "Give a seed value or an empty line: ";
    std::string seed = "";
    getline(std::cin, seed);

    if(seed == "") {
        // If the user did not give a seed value, use computer time as the seed
        // value.
        rEng.seed(time(NULL));
    } else {
        // If the user gave a seed value, use it.
        rEng.seed(stoi(seed));
    }

    // Add some tiles to the board.
    for ( int i = 0 ; i < SIZE ; ++i ){
        newValue(board, rEng, distr);
    }
    std::cout << "Give a goal value or an empty line: ";
    std::string goal;
    getline(std::cin, goal);
    if (!is_int(goal)){
        return DEFAULT_GOAL;
    }
    else if(goal == "") {
        return DEFAULT_GOAL;
    }
return std::stoi(goal);
}



// Prints the board.
void print(std::vector<std::vector<NumberTile>> &board){
    // The y isn't actually the y coordinate or some int, but an iterator that
    // is like a vector of NumberTiles.
    for ( auto y : board ){
        // Prints a row of dashes.
        std::cout << std::string(PRINT_WIDTH * SIZE + 1, '-') << std::endl;
        // And then print all cells in the desired width.
        for ( auto x : y ){
            x.print(PRINT_WIDTH);
        }
        // And a line after each row.
        std::cout << "|" << std::endl;
    }
    // Print a last row of dashes so that the board looks complete.
    std::cout << std::string(PRINT_WIDTH * SIZE + 1, '-') << std::endl;
}

int greatest_value(std::vector<std::vector<NumberTile>> &board){
    int greatest = 0;
    int& biggest = greatest;
    for ( auto y = 0; y < SIZE; y++ ){
            for ( auto x = 0; x < SIZE; x++ ){
                if (board.at(x).at(y).getValue() > biggest){
                    biggest = board.at(x).at(y).getValue();
                }
            }
        }
    return biggest;
}

bool game_over(std::vector<std::vector<NumberTile>> &board){
    for (int y=0; y<SIZE; ++y){
        for (int x=0; x<SIZE;++x){
            if (board.at(y).at(x).getValue()==0){
                return false;
            }
        }
    }return true;
}

void move_board(std::vector<std::vector<NumberTile>> &board, char dir){
    if (dir == 'a'){
        int i  = 1;
        for ( auto y = 0; y < SIZE; y++ ){
                for ( auto x = 0; x < SIZE-1; x++ ){
                    i=1;
                    if (board.at(y).at(0).getValue() == board.at(y).at(1).getValue() && board.at(y).at(1).getValue() == board.at(y).at(2).getValue() && board.at(y).at(2).getValue() == board.at(y).at(3).getValue()){
                        board.at(y).at(0).setValue(2 * board.at(y).at(0).getValue());
                        board.at(y).at(1).setValue(2 * board.at(y).at(1).getValue());
                        board.at(y).at(2).setValue(0);
                        board.at(y).at(3).setValue(0);
                    }
                    else if (board.at(y).at(x).getValue() == 0){
                        while (board.at(y).at(x+i).getValue() == 0 && i < SIZE-x-1){
                            ++i;
                            }
                        if (board.at(y).at(x+i).getValue() != 0){
                            board.at(y).at(x).setValue(board.at(y).at(x+i).getValue());
                            board.at(y).at(x+i).setValue(0);
                            --x;
                            }
                    }else{
                        while (board.at(y).at(x+i).getValue() == 0 && i < SIZE-x-1){
                            ++i;
                            }
                            if (board.at(y).at(x+i).getValue() == board.at(y).at(x).getValue()){
                                board.at(y).at(x).setValue(2 * board.at(y).at(x).getValue());
                                board.at(y).at(x+i).setValue(0);
                            }
                            else if (board.at(y).at(x+i).getValue() != board.at(y).at(x).getValue()){
                                board.at(y).at(x+1).setValue(board.at(y).at(x+i).getValue());
                                if (i!=1){
                                    board.at(y).at(x+i).setValue(0);
                                }
                            }
                }
            }
         }
    }
    if (dir == 'd'){
        int i  = 1;
        for ( auto y = 0; y < SIZE; y++ ){
                for ( auto x = SIZE-1; x > 0 ; x-- ){
                    i=1;
                    if (board.at(y).at(0).getValue() == board.at(y).at(1).getValue() && board.at(y).at(1).getValue() == board.at(y).at(2).getValue() && board.at(y).at(2).getValue() == board.at(y).at(3).getValue()){
                        board.at(y).at(2).setValue(2 * board.at(y).at(2).getValue());
                        board.at(y).at(3).setValue(2 * board.at(y).at(3).getValue());
                        board.at(y).at(0).setValue(0);
                        board.at(y).at(1).setValue(0);
                    }
                    else if (board.at(y).at(x).getValue() == 0){
                        while (board.at(y).at(x-i).getValue() == 0 && i <= x-1){
                            ++i;
                            }
                        if (board.at(y).at(x-i).getValue() != 0){
                            board.at(y).at(x).setValue(board.at(y).at(x-i).getValue());
                            board.at(y).at(x-i).setValue(0);
                            ++x;
                            }
                    }else{
                        while (board.at(y).at(x-i).getValue() == 0 && i <= x-1){
                            ++i;
                            }
                            if (board.at(y).at(x-i).getValue() == board.at(y).at(x).getValue()){
                                board.at(y).at(x).setValue(2 * board.at(y).at(x).getValue());
                                board.at(y).at(x-i).setValue(0);
                            }
                            else if (board.at(y).at(x-i).getValue() != board.at(y).at(x).getValue()){
                                board.at(y).at(x-1).setValue(board.at(y).at(x-i).getValue());
                                if (i!=1){
                                    board.at(y).at(x-i).setValue(0);
                                }
                            }
                }
            }
         }
    }
    if (dir == 'w'){
        int i  = 1;
        for ( auto x = 0; x < SIZE; x++ ){
                for ( auto y = 0; y < SIZE-1; y++ ){
                    i=1;
                    if (board.at(0).at(x).getValue() == board.at(1).at(x).getValue() && board.at(1).at(x).getValue() == board.at(2).at(x).getValue() && board.at(2).at(x).getValue() == board.at(3).at(x).getValue()){
                        board.at(0).at(x).setValue(2 * board.at(0).at(x).getValue());
                        board.at(1).at(x).setValue(2 * board.at(1).at(x).getValue());
                        board.at(2).at(x).setValue(0);
                        board.at(3).at(x).setValue(0);
                    }
                    else if (board.at(y).at(x).getValue() == 0){
                        while (board.at(y+i).at(x).getValue() == 0 && i < SIZE-y-1){
                            ++i;
                            }
                        if (board.at(y+i).at(x).getValue() != 0){
                            board.at(y).at(x).setValue(board.at(y+i).at(x).getValue());
                            board.at(y+i).at(x).setValue(0);
                            --y;
                    }

                    }else{
                        while (board.at(y+i).at(x).getValue() == 0 && i < SIZE-y-1){
                            ++i;
                            }
                        if (board.at(y).at(x).getValue() != 0){
                            if (board.at(y+i).at(x).getValue() == board.at(y).at(x).getValue()){
                                board.at(y).at(x).setValue(2 * board.at(y).at(x).getValue());
                                board.at(y+i).at(x).setValue(0);
                            }
                            else if (board.at(y+i).at(x).getValue() != board.at(y).at(x).getValue()){
                                board.at(y+1).at(x).setValue(board.at(y+i).at(x).getValue());
                                if (i!=1){
                                    board.at(y+i).at(x).setValue(0);
                                }
                            }
                    }
                }
            }
         }
    }
    if (dir == 's'){
        int i  = 1;
        for ( auto x = 0; x < SIZE; x++ ){
                for ( auto y = 3; y > 0; y-- ){
                    i=1;
                    if (board.at(0).at(x).getValue() == board.at(1).at(x).getValue() && board.at(1).at(x).getValue() == board.at(2).at(x).getValue() && board.at(2).at(x).getValue() == board.at(3).at(x).getValue()){
                        board.at(2).at(x).setValue(2 * board.at(2).at(x).getValue());
                        board.at(3).at(x).setValue(2 * board.at(3).at(x).getValue());
                        board.at(0).at(x).setValue(0);
                        board.at(1).at(x).setValue(0);
                    }
                    else if (board.at(y).at(x).getValue() == 0){
                        while (board.at(y-i).at(x).getValue() == 0 && i <= y-1){
                            ++i;
                            }
                        if (board.at(y-i).at(x).getValue() != 0){
                            board.at(y).at(x).setValue(board.at(y-i).at(x).getValue());
                            board.at(y-i).at(x).setValue(0);
                            ++y;
                    }

                    }else{
                        while (board.at(y-i).at(x).getValue() == 0 && i <= y-1){
                            ++i;
                            }
                        if (board.at(y).at(x).getValue() != 0){
                            if (board.at(y-i).at(x).getValue() == board.at(y).at(x).getValue()){
                                board.at(y).at(x).setValue(2 * board.at(y).at(x).getValue());
                                board.at(y-i).at(x).setValue(0);
                            }
                            else if (board.at(y-i).at(x).getValue() != board.at(y).at(x).getValue()){
                                board.at(y-1).at(x).setValue(board.at(y-i).at(x).getValue());
                                if (i!=1){
                                    board.at(y-i).at(x).setValue(0);
                                }
                            }
                    }
                }
            }
         }
    }
}



int game(std::vector<std::vector<NumberTile>> &board, std::default_random_engine &rEng,
         std::uniform_int_distribution<int> &distr, int goal){
    while (true){
        std::cout << "Dir> ";
        char dir;
        std::cin >> dir;
        // Check for viable commands
        if (dir != 'a' && dir != 'd' && dir != 's' && dir != 'w' && dir != 'q'){
            std::cout << "Error: unknown command." << std::endl;
            continue;
        }
        // User wants to stop the game
        if (dir == 'q'){
            return 0;

        // Tähän tulee pelilauden muutoksen toiminta
        }else{
            move_board(board, dir);
            if (greatest_value(board) >= goal){
                print(board);
                std::cout << "You reached the goal value of " << goal << "!" << std::endl;
                return 0;
            }
            while(!board.at(distr(rEng)).at(distr(rEng)).setValue(NEW_VALUE, true));
            print(board);
            if (game_over(board)){
                std::cout << "Can't add new tile, you lost!" << std::endl;
                return 0;
            }
        }
    }
}



int main()
{
    // Declare the board and randomengine.
    std::vector<std::vector<NumberTile>> board;
    std::default_random_engine randomEng;
    // And initialize the disrt to give numbers from the correct
    std::uniform_int_distribution<int> distr(0, SIZE - 1);
    int goal;
    goal = initBoard(board, randomEng, distr);
    print(board);
    game(board, randomEng, distr, goal);
}
