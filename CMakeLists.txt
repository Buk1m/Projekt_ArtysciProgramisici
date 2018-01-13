cmake_minimum_required(VERSION 3.9)
project(Projekt_ArtysciProgramisici)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projekt_ArtysciProgramisici program/main.cpp
        library/src/Repository.cpp library/include/Repository.h
        library/src/Order.cpp library/include/Order.h
        library/src/ShipmentType.cpp library/include/ShipmentType.h
        library/src/PaymentType.cpp library/include/PaymentType.h
        library/src/Client.cpp library/include/Client.h
        library/src/Cart.cpp library/include/Cart.h
        library/src/Merchandise.cpp library/include/Merchandise.h
        library/src/Address.cpp library/include/Address.h
        library/src/ClientsManager.cpp library/include/ClientsManager.h
        library/src/ClientsRepository.cpp library/include/ClientsRepository.h library/src/MerchandisesRepository.cpp library/include/MerchandisesRepository.h library/src/MerchandisesManager.cpp library/include/MerchandisesManager.h library/src/OrdersRepository.cpp library/include/OrdersRepository.h)

set(BOOST_ROOT "C:/boost/boost_1_55_0/boost_1_55_0")

find_package(Boost 1.55.0)

if (NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif ()
