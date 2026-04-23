#include "checkers.h"
#include <string>

bool IsValidNotation(const std::string& userInput){

    // length check
    if (userInput.length() != 2){
        return false;
    }
    // char at index 0 should be a letter between a-h
    int file = tolower(userInput.at(0));
    if (file < 97 || file > 104){
        return false;
    }

    // char at index 1 should be a number between 1-8
    char rank = userInput.at(1);
    if (rank < '1' || rank > '8'){
        return false;
    }

    return true;
}