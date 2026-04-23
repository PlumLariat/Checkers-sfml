#pragma once

#include <string>
#include "types.h"

class Piece {

    public:
        Piece(Color color, Type type);
        ~Piece();
        
        Color getColor();
        void setColor(Color color);

        Type getType();
        void setType(Type type);
        
        std::string toString();

        bool operator==(const Piece &otherPiece) const;
        bool operator!=(const Piece &otherPiece) const;

    private:
        Color color;
        Type type;
};