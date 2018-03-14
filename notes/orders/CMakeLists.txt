
project(war CXX)
cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_FLAGS "-std=c++1z")

find_package(curses)

# Declare a library named `cards`.
add_library(cards
  card.cpp
  badcard.cpp
  goodcard.cpp
  bitcard.cpp)

# Declares an executable program `shuffle`.
add_executable(shuffle
  shuffle.cpp)

# Just an example
set(libs ${CURSES_LIBRARIES})

# Specifies that shuffle should link against
# the library cards. This basically tells
# CMake to compile the executable like this:
#
#   $CXX <inputs> -lcards
#
target_link_libraries(shuffle cards ${libs})


