project(card CXX)
cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_FLAGS "-std=c++1z")

# Declares an executable program `main`.
add_executable(deck deck.cpp main.cpp)
