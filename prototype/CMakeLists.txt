cmake_minimum_required(VERSION 3.28)
project(CheckersPrototype)

enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.17.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(proto_lib
    src/checkers.cpp
    src/board.cpp
    src/piece.cpp
)
target_include_directories(proto_lib PUBLIC src/)


add_executable(checkers_proto src/main.cpp)
target_link_libraries(checkers_proto PRIVATE proto_lib)


add_subdirectory(tests)