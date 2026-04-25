#pragma once
#include <string>

class Move {
    private:
        unsigned int startX;
        unsigned int startY;
        unsigned int endX;
        unsigned int endY;
        std::pair<unsigned int, unsigned int> NotationToCoords(std::string &notationString); 

    public:
        Move(std::string &userInput);
        ~Move();
        static bool IsValidNotation(const std::string& userInput);
        
        void setStartX(unsigned int startX);
        unsigned int GetStartX();
        void setStartY(unsigned int startY);
        unsigned int GetStartY();

        void setEndX(unsigned int EndX);
        unsigned int GetEndX();
        void setEndY(unsigned int EndY);
        unsigned int GetEndY();


};