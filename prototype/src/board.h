#pragma once

#include "piece.h"
#include <optional>

//! specifies both the board's width and height
const int BOARD_SIZE = 8;

class Board {
    private:
        std::optional<Piece> tiles[BOARD_SIZE][BOARD_SIZE];
        void addPieceToTile(unsigned int x, unsigned int y, Color color);
    public:
        Board();
        ~Board();
        void Init();
        void Draw();
        std::optional<Piece> getPieceAt(unsigned int x, unsigned int y);
};

