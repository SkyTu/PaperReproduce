cmake_minimum_required(VERSION 3.15)

PROJECT(OTextension)

include_directories(/usr/local/include/cryptopp)

add_executable(sender ../PrimeGroup.cpp ../PrimeGroup.hpp sender.cpp)

target_link_libraries(sender /usr/local/lib/libcryptopp.a)
target_link_libraries(sender /usr/local/lib/libcryptopp.so)
target_link_libraries(sender /usr/local/lib/libcryptopp.so.8)
target_link_libraries(sender /usr/local/lib/libcryptopp.so.8.7.0)