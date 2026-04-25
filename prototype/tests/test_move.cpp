#include <gtest/gtest.h>
#include "move.h"

#include <string>

TEST(TestMoveValidNotation, ValidNotationWhiteMovingDown) {
    std::string userInput = "b3c4";
    bool result = Move::IsValidNotation(userInput);
    EXPECT_EQ(result, true);
}

TEST(TestMoveValidNotation, ValidNotationBlackMovingUp) {
    std::string userInput = "g6h5";
    bool result = Move::IsValidNotation(userInput);
    EXPECT_EQ(result, true);
}

TEST(TestMoveValidNotation, ValidNotationInvalidMove) {
    std::string userInput = "a1h8";
    bool result = Move::IsValidNotation(userInput);
    EXPECT_EQ(result, true);
}

TEST(TestMoveValidNotation, ArbitraryUserInput) {
    std::string userInput = "not a valid move";
    bool result = Move::IsValidNotation(userInput);
    EXPECT_EQ(result, false);
}

TEST(TestMoveValidNotation, UserInputLongLengthBoundsCheck) {
    std::string userInput = "a1b22";
    bool result = Move::IsValidNotation(userInput);
    EXPECT_EQ(result, false);
}

TEST(TestMoveValidNotation, UserInputShortLengthBoundsCheck) {
    std::string userInput = "ab2";
    bool result = Move::IsValidNotation(userInput);
    EXPECT_EQ(result, false);
}

TEST(TestMoveValidNotation, InvalidFile) {
    std::string userInput = "h1i2";
    bool result = Move::IsValidNotation(userInput);
    EXPECT_EQ(result, false);
}

TEST(TestMoveValidNotation, InvalidRank) {
    std::string userInput = "d1c0";
    std::string userInput2 = "d9c2";

    bool result = Move::IsValidNotation(userInput);
    EXPECT_EQ(result, false);

    bool result2 = Move::IsValidNotation(userInput2);
    EXPECT_EQ(result2, false);
}

TEST(TestMoveValidNotation, UppercaseIsValid) {
    std::string userInput = "F7E6";
    bool result = Move::IsValidNotation(userInput);
    EXPECT_EQ(result, true);
}