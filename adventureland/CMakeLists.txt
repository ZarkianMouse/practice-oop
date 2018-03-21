cmake_minimum_required(VERSION 2.8)

project(advland CXX)
set(CMAKE_CXX_FLAGS "-std=c++1z")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(advland 
  main.cpp
  advland.cpp
  )
target_link_libraries(advland ${CURSES_LIBRARIES})





