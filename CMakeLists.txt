cmake_minimum_required(VERSION 3.9)

#Configuration parameters of cmake
set(CMAKE_CXX_COMPILER g++)#requires g++ to be available on PATH
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Projekt_ArtysciProgramisici)
enable_language(CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE TRUE)

#Source files her
set(SOURCE_FILES
    program/main.cpp
        library/src/Repositories/Repository.cpp library/include/Repositories/Repository.h
    library/src/Order.cpp library/include/Order.h
    library/src/ShipmentType.cpp library/include/ShipmentType.h
    library/src/PaymentType.cpp library/include/PaymentType.h
    library/src/Client.cpp library/include/Client.h
    library/src/Cart.cpp library/include/Cart.h
    library/src/Merchandise.cpp library/include/Merchandise.h
    library/src/Address.cpp library/include/Address.h
        library/src/Managers/ClientsManager.cpp library/include/Managers/ClientsManager.h
        library/src/Repositories/ClientsRepository.cpp library/include/Repositories/ClientsRepository.h
        library/src/Repositories/MerchandisesRepository.cpp library/include/Repositories/MerchandisesRepository.h
        library/src/Managers/MerchandisesManager.cpp library/include/Managers/MerchandisesManager.h
        library/src/Repositories/OrdersRepository.cpp library/include/Repositories/OrdersRepository.h
    library/src/CourierDelivery.cpp library/include/CourierDelivery.h
    library/src/SelfPickup.cpp library/include/SelfPickup.h
    library/src/CashPayment.cpp library/include/CashPayment.h
    library/src/CardPayment.cpp library/include/CardPayment.h
    library/src/Merchandises/Laptop.cpp library/include/Merchandises/Laptop.h
    library/src/Merchandises/Smartphone.cpp library/include/Merchandises/Smartphone.h
        library/src/Exceptions/ClientException.cpp library/include/Exceptions/ClientException.h
        library/src/Exceptions/OrderException.cpp library/include/Exceptions/OrderException.h
        library/src/Exceptions/MerchandiseException.cpp library/include/Exceptions/MerchandiseException.h)

add_executable(Projekt_ArtysciProgramisici ${SOURCE_FILES})

target_include_directories(Projekt_ArtysciProgramisici PUBLIC include)

#TESTs
find_package (Boost 1.66.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
${CMAKE_CURRENT_SOURCE_DIR}/include
${Boost_INCLUDE_DIRS}
)

#Test source files here
set(SOURCE_TEST_FILES
    test/master.cpp
    test/TestClient.cpp
        library/src/Repositories/Repository.cpp library/include/Repositories/Repository.h
    library/src/Order.cpp library/include/Order.h
    library/src/ShipmentType.cpp library/include/ShipmentType.h
    library/src/PaymentType.cpp library/include/PaymentType.h
    library/src/Client.cpp library/include/Client.h
    library/src/Cart.cpp library/include/Cart.h
    library/src/Merchandise.cpp library/include/Merchandise.h
    library/src/Address.cpp library/include/Address.h
        library/src/Managers/ClientsManager.cpp library/include/Managers/ClientsManager.h
        library/src/Repositories/ClientsRepository.cpp library/include/Repositories/ClientsRepository.h
        library/src/Repositories/MerchandisesRepository.cpp library/include/Repositories/MerchandisesRepository.h
        library/src/Managers/MerchandisesManager.cpp library/include/Managers/MerchandisesManager.h
        library/src/Repositories/OrdersRepository.cpp library/include/Repositories/OrdersRepository.h
    library/src/CourierDelivery.cpp library/include/CourierDelivery.h
    library/src/SelfPickup.cpp library/include/SelfPickup.h
    library/src/CashPayment.cpp library/include/CashPayment.h
    library/src/CardPayment.cpp library/include/CardPayment.h
    library/src/Merchandises/Laptop.cpp library/include/Merchandises/Laptop.h
        library/src/Exceptions/ClientException.cpp library/include/Exceptions/ClientException.h
        library/src/Exceptions/OrderException.cpp library/include/Exceptions/OrderException.h)

add_executable(TestProject ${SOURCE_TEST_FILES} )

target_include_directories(TestProject PUBLIC include)

target_link_libraries (TestProject
${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

enable_testing()

add_test(NAME Test COMMAND TestProject
--report_level=detailed
--log_level=all
--color_output=yes)

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
