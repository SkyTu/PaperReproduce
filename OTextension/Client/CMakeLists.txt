cmake_minimum_required(VERSION 3.15)

PROJECT(OTextension)

set(CMAKE_CXX_STANDARD 11)

include_directories(/usr/local/include/cryptopp)

add_executable(reciever ../PrimeGroup.cpp ../PrimeGroup.hpp reciever.cpp)

target_link_libraries(reciever /usr/local/lib/libcryptopp.a)
target_link_libraries(reciever /usr/local/lib/libcryptopp.so)
target_link_libraries(reciever /usr/local/lib/libcryptopp.so.8)
target_link_libraries(reciever /usr/local/lib/libcryptopp.so.8.7.0)