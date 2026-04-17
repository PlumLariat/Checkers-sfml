/*!
 * \file main.cpp
 * \brief driver file for a simple game of console checkers.
 * \author Eric Jeffcoat
 * \date 2026-04-17
 */

#include <iostream>
#include <string>

using namespace std;

//! specifies both the board's width and height
const int BOARD_SIZE = 8;

/*!
 * \enum Tile
 * \brief Definition for all possible states of the board in a tile.
 */

enum Tile { vacant, white, black };

/*!
 * \brief Draws the current board state to the terminal.
 * 
 * \param board 
 */
void DrawBoard(Tile board[][BOARD_SIZE]);

/*!
 * \brief Initializes the starting board state for a new game of checkers.
 * 
 * \param board 
 */
void InitBoard(Tile board[][BOARD_SIZE]);

int main(){
    
    // 2D array tracking board state
    Tile board[BOARD_SIZE][BOARD_SIZE];

    InitBoard(board);
    DrawBoard(board);

    return 0;
}

//! \copydoc InitBoard
void InitBoard(Tile board[][BOARD_SIZE]){

    // start the board with all vacant tiles
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = vacant;
        }
    }

    // assemble white's back row pieces
    for (int i = 1; i < BOARD_SIZE; i = i + 2){
        board[0][i] = white;
    }

    // assemble white's middle row pieces
    for (int i = 0; i < BOARD_SIZE; i = i + 2){
        board[1][i] = white;
    }

    // assemble white's front row pieces
    for (int i = 1; i < BOARD_SIZE; i = i + 2){
        board[2][i] = white;
    }

    // assemble black's back row pieces
    for (int i = 0; i < BOARD_SIZE; i = i + 2){
        board[BOARD_SIZE - 1][i] = black;
    }

    // assemble black's middle row pieces
    for (int i = 1; i < BOARD_SIZE; i = i + 2){
        board[BOARD_SIZE - 2][i] = black;
    }

    // assemble black's front row pieces
    for (int i = 0; i < BOARD_SIZE; i = i + 2){
        board[BOARD_SIZE - 3][i] = black;
    }

}

//! \copydoc DrawBoard
void DrawBoard(Tile board[][BOARD_SIZE]){
    cout << "    a   b   c   d   e   f   g   h  \n";
    cout << "  ---------------------------------\n";
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << to_string(i + 1) << " |";
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch(board[i][j]) {
                case vacant:
                    cout << "   |";
                    break;
                case white:
                    cout << " W |";
                    break;
                case black:
                    cout << " B |";
                    break;
            }
        }
        cout << "\n";
        cout << "  ---------------------------------\n";
    }
}