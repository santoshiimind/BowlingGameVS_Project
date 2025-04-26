
cmake_minimum_required(VERSION 3.10)
project(BowlingGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(BowlingGame main.cpp BowlingGame.cpp)
add_executable(BowlingGameTests test.cpp BowlingGame.cpp)
