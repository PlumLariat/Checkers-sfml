#include "board.h"
#include "piece.h"
#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>

Board::Board() {

}

Board::~Board() {

}

void Board::addPieceToTile(unsigned int x, unsigned int y, Color color){
    if (x >= BOARD_SIZE || y >= BOARD_SIZE) {
        throw std::out_of_range("Given tile coords out of bounds.");
    } 
    Piece p = Piece(color, Type::man);
    this->tiles[x][y] = p;
}

void Board::removePieceFromTile(unsigned int x, unsigned int y) {
    if (x >= BOARD_SIZE || y >= BOARD_SIZE) {
        throw std::out_of_range("Given tile coords out of bounds.");
    }
    this->tiles[x][y] = std::nullopt;
}

void Board::Init(){

    // assemble white's back row pieces
    for (int i = 1; i < BOARD_SIZE; i = i + 2){
        this->addPieceToTile(0, i, Color::light); 
    }

    // assemble white's middle row pieces
    for (int i = 0; i < BOARD_SIZE; i = i + 2){
        this->addPieceToTile(1, i, Color::light);
    }

    // assemble white's front row pieces
    for (int i = 1; i < BOARD_SIZE; i = i + 2){
        this->addPieceToTile(2, i, Color::light);
    }

    // assemble black's back row pieces
    for (int i = 0; i < BOARD_SIZE; i = i + 2){
        this->addPieceToTile(BOARD_SIZE - 1, i, Color::dark);
    }

    // assemble black's middle row pieces
    for (int i = 1; i < BOARD_SIZE; i = i + 2){
        this->addPieceToTile(BOARD_SIZE - 2, i, Color::dark);
    }

    // assemble black's front row pieces
    for (int i = 0; i < BOARD_SIZE; i = i + 2){
        this->addPieceToTile(BOARD_SIZE - 3, i, Color::dark);
    }

}

void Board::Draw(){
    std::cout << "    a   b   c   d   e   f   g   h  \n";
    std::cout << "  ---------------------------------\n";
    for (int i = 0; i < BOARD_SIZE; i++) {
        std::cout << std::to_string(i + 1) << " |";
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (this->tiles[i][j].has_value()){
                std::cout << " " + this->tiles[i][j].value().toString() + " |";
            } else {
                std::cout << "   |";
            }
        }
        std::cout << "\n";
        std::cout << "  ---------------------------------\n";
    }
}

std::optional<Piece> Board::getPieceAt(unsigned int x, unsigned int y) {
    if (this->tiles[x][y]) {
        return this->tiles[x][y].value();
    } else {
        return std::nullopt;
    }
}