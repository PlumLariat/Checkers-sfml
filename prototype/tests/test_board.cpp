#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "board.h"
#include "types.h"
#include "piece.h"
void rowCheckingAssistant(Board &board, bool piecesStartAtZero, int row, Color color);

TEST(BoardTest, TestInitializeBoard) {
    Board board;
    board.Init();
    // test starting 0-2 rows
    rowCheckingAssistant(board, true, 0, Color::light);
    rowCheckingAssistant(board, false, 1, Color::light);
    rowCheckingAssistant(board, true, 2, Color::light);

    // test empty 3-4 rows
    for (int i = 0; i < BOARD_SIZE; i++){
        EXPECT_FALSE(board.getPieceAt(3, i).has_value());
    }
    for (int i = 0; i < BOARD_SIZE; i++){
        EXPECT_FALSE(board.getPieceAt(4, i).has_value());
    }

    rowCheckingAssistant(board, false, 5, Color::dark);
    rowCheckingAssistant(board, true, 6, Color::dark);
    rowCheckingAssistant(board, false, 7, Color::dark);
}

void rowCheckingAssistant(Board &board, bool piecesStartAtZero, int row, Color color) {
   if(piecesStartAtZero) {
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (i % 2 == 0) {
                EXPECT_FALSE(board.getPieceAt(row,i).has_value());
            } else {
                EXPECT_TRUE(board.getPieceAt(row,i).has_value());
                EXPECT_EQ(board.getPieceAt(row,i).value(), Piece(color, Type::man));
            }   
        } 
    }
    else {
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (i % 2 == 0) {
                EXPECT_TRUE(board.getPieceAt(row,i).has_value());
                EXPECT_EQ(board.getPieceAt(row,i).value(), Piece(color, Type::man));
            } else {
                EXPECT_FALSE(board.getPieceAt(row,i).has_value());
            }
        }
    }
}