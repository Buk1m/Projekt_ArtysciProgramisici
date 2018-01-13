cmake_minimum_required(VERSION 3.9)
project(Projekt_ArtysciProgramisici)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projekt_ArtysciProgramisici program/main.cpp
               library/src/Repository.cpp library/include/Repository.h)