#include <gtest/gtest.h>
#include "piece.h"
#include "types.h"

TEST(PieceTest, TestToStringDarkMan){
    Piece p = Piece(Color::dark, Type::man);
    EXPECT_EQ(p.toString(), "b");
}

TEST(PieceTest, TestToStringDarkKing){
    Piece p = Piece(Color::dark, Type::king);
    EXPECT_EQ(p.toString(), "B");
}

TEST(PieceTest, TestToStringLightMan){
    Piece p = Piece(Color::light, Type::man);
    EXPECT_EQ(p.toString(), "w");
}

TEST(PieceTest, TestToStringLightKing){
    Piece p = Piece(Color::light, Type::king);
    EXPECT_EQ(p.toString(), "W");
}

TEST(PieceTest, TestPieceEquality) {
    Piece p1 = Piece(Color::light, Type::man);
    Piece p2 = Piece(Color::light, Type::man);
    Piece p3 = Piece(Color::dark, Type::man);
    Piece p4 = Piece(Color::dark, Type::king);
    Piece p5 = Piece(Color::dark, Type::king);

    EXPECT_EQ(p1, p2);
    EXPECT_NE(p1, p3);
    EXPECT_NE(p2, p4);
    EXPECT_EQ(p4, p5);

}