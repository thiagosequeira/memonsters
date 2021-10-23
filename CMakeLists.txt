cmake_minimum_required(VERSION 3.15)
project(proyecto-infoII)

include_directories("D:\\mingw64\\include")
set(CMAKE_CXX_STANDARD 14)

add_executable(proyecto main.cpp classes/player.h classes/player.cpp auxiliary/LinkedList.h auxiliary/Node.h)
target_link_libraries(proyecto sfml-graphics sfml-audio sfml-system sfml-window)
