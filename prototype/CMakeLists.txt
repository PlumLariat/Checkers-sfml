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

add_executable(checkers_proto src/main.cpp)

add_subdirectory(tests)