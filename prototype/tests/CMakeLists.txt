add_executable(proto_tests test_main.cpp)

target_link_libraries(proto_tests PRIVATE GTest::gtest_main)

include(GoogleTest)
add_test(NAME SanityCheck COMMAND proto_tests)