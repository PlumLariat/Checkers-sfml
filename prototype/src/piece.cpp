#include "piece.h"

Piece::Piece(Color color, Type type) {
    this->color = color;
    this->type = type;
}

Piece::~Piece(){
    
}

Color Piece::getColor() {
    return this->color;
}

void Piece::setColor(Color color) {
    this->color = color;
}

Type Piece::getType() {
    return this->type;
}

void Piece::setType(Type type) {
    this->type = type;
}

std::string Piece::toString() {
    std::string token = " ";

    if (this->color == Color::dark) {
        if (this->type == Type::king) {
            token = "B";
        } else {
            token = "b";
        }
    } else if (this->color == Color::light) {
        if (this->type == Type::king) {
            token = "W";
        } else {
            token = "w";
        }
    }

    return token;
}

bool Piece::operator==(const Piece &otherPiece) const {
    if (this->color == otherPiece.color && this->type == otherPiece.type) {
        return true;
    }
    return false;
}

bool Piece::operator!=(const Piece &otherPiece) const {
    if (this->color != otherPiece.color || this->type != otherPiece.type) {
        return true;
    }
    return false;
}