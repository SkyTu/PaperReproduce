cmake_minimum_required(VERSION 3.15)

PROJECT(SecureML)

set(CMAKE_CXX_STANDARD 11)

add_executable(test1 test.cpp Utils.cpp Utils.hpp)