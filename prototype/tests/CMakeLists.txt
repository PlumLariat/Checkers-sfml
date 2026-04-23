add_executable(proto_tests
    test_piece.cpp
    test_board.cpp
)

target_link_libraries(proto_tests PRIVATE proto_lib GTest::gtest_main GTest::gmock_main)

include(GoogleTest)
gtest_discover_tests(proto_tests)