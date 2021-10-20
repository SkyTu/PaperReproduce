cmake_minimum_required(VERSION 3.15)

PROJECT(OTextension)

set(CMAKE_CXX_STANDARD 11)

add_executable(test PrimeGroup.cpp PrimeGroup.hpp test.cpp)