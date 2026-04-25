/*!
 * \file main.cpp
 * \brief driver file for a simple game of console checkers.
 * \author Eric Jeffcoat
 * \date 2026-04-17
 */

#include <iostream>
#include <string>
#include <limits>

#include "board.h"

using namespace std;

int main(){
    
    
    // boolean to check the game loop
    bool running = true;
    Board board;

    board.Init();
    board.Draw();

    string userInput;

    // for(;;){
    //     cout << "Enter a move in algebraic notation: ";
    //     if (cin >> userInput && IsValidNotation(userInput)){
    //         break;
    //     } else {
    //         cout << "Invalid input detected. Your input should look something like: e4" << endl;
    //         cin.clear();
    //         cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //     }
    // }
    // cout << "Your input was: " << userInput << "\n";


    return 0;
}
