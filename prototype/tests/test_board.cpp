#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "board.h"
#include "types.h"
#include "piece.h"

TEST(BoardTest, TestInitializeBoard) {
    Board board;
    board.Init();

    // row 0
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (i % 2 == 0) {
            EXPECT_FALSE(board.getPieceAt(0,i).has_value());
        } else {
            EXPECT_TRUE(board.getPieceAt(0,i).has_value());
            EXPECT_EQ(board.getPieceAt(0,i).value(), Piece(Color::light, Type::man));
        }
    }
}