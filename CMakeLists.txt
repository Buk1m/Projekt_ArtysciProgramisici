cmake_minimum_required(VERSION 3.9)
project(Projekt_ArtysciProgramisici)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projekt_ArtysciProgramisici program/main.cpp
<<<<<<< HEAD
               library/src/Repository.cpp library/include/Repository.h
               library/src/Order.cpp library/include/Order.h
        library/src/ShipmentType.cpp library/include/ShipmentType.h
        library/src/PaymentType.cpp library/include/PaymentType.h)

set(BOOST_ROOT "C:/boost/boost_1_55_0/boost_1_55_0")

find_package(Boost 1.55.0)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()
