# Part 1: Writing a Console Prototype

This might not seem like it, but this is a pretty complex project and it would
probably help if it were broken down into smaller pieces that could later be
recombined. I think a good decision would be to separate out the games graphics
from its logic as a start. What better way to do this than to first write up a
console-only prototype.

We'll begin with a single file and refactor things out as it makes sense to do
so.

It seems like a good place to begin would be to figure out how to represent the
board, then we should be able to initialize the starting pieces, and then draw
them out to the terminal.

## Defining our board
Standard checkers boards will have 8 tiles that span both across and down. We
can utilize an integer constant to define the unchanging size of the board which
we will reference in later portions of our code. Since there is really no need
to ever have to resize the board, so that narrows us down to a representation
with a datatype that should live on the stack. It seems pretty obvious to me
that a multidimensional array should serve the application well and accomplish
what we set out to do in these early stages. 

The actual primitive datatype we should use to populate our basic 2-D array is
slightly open to interpretation. Its entirely possible to fill it with int, chars,
or even strings (if you're into that sort of thing), but I think that the most
readable solution is to use an enum. The board's tiles in a game of checkers will
only ever hold one of three states at a time, so this is a very readable choice.

This takes us to the bare-bones start of the application:

```C++
const int BOARD_SIZE = 8;
enum Tile { vacant, white, black };

int main(){
    
    // 2D array tracking board state
    Tile board[BOARD_SIZE][BOARD_SIZE];

    return 0;
}
```

Here is the final snippet that combines everything together, with Doxygen style
comments:
```C++
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
```