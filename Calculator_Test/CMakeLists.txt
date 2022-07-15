cmake_minimum_required(VERSION 3.5)

project(AutoTest LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
        HPFloat.h
        tst_autotest.cpp
        test_1.txt
        test_2.txt
        test_3.txt
        test_4.txt
        test_5.txt
        test_6.txt
        test_7.txt
        test_8.txt
        test_9.txt
        test_10.txt
)

add_executable(AutoTest tst_autotest.cpp)
add_test(NAME AutoTest COMMAND AutoTest)

target_link_libraries(AutoTest PRIVATE Qt${QT_VERSION_MAJOR}::Test)

