#include "move.h"
#include <stdexcept>

Move::Move(std::string &userInput) {
    if (this->IsValidNotation(userInput)) {
        // auto moveStrStart = userInput.substr(0,2);
        // auto moveStrEnd = userInput.substr(2,2);
        // auto startMovePair = this->NotationToCoords(moveStrStart);
        // auto endMovePair =  this->NotationToCoords(moveStrEnd);

        // this->setStartX(startMovePair.first);
        // this->setStartY(startMovePair.second);
        // this->setEndX(endMovePair.first);
        // this->setEndY(endMovePair.second);
    } else {
        throw std::invalid_argument("UserInput is not valid algebraic notation.");
    }
}


bool Move::IsValidNotation(const std::string& userInput) {
    // length check
    if (userInput.length() != 4){
        return false;
    }
    // char at index 0 should be a letter between a-h
    int startFile = tolower(userInput.at(0));
    int endFile = tolower(userInput.at(2));
    if ((startFile < 97 || startFile > 104) || (endFile < 97 || endFile > 104)){
        return false;
    }

    // char at index 1 should be a number between 1-8
    char startRank = userInput.at(1);
    char endRank = userInput.at(3);
    if ((startRank < '1' || startRank > '8') || (endRank < '1' || endRank > '8')){
        return false;
    }

    return true;
}


std::pair<unsigned int, unsigned int> NotationToCoords(std::string &notationString) {
    return std::pair(1,1);
}

void Move::setStartX(unsigned int startX) {
    this->startX = startX;
}
unsigned int Move::GetStartX() {
    return this->startX;
}
void Move::setStartY(unsigned int startY) {
    this->startY = startY;
}
unsigned int Move::GetStartY() {
    return this->startY;
}
void Move::setEndX(unsigned int endX) {
    this->endX = endX;
}
unsigned int Move::GetEndX() {
    return this->endX;
}
void Move::setEndY(unsigned int EndY) {
    this->endY = endY;
}
unsigned int Move::GetEndY() {
    return this->endY;
}

