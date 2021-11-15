cmake_minimum_required(VERSION 3.15)

PROJECT(OTextension)

set(CMAKE_CXX_STANDARD 11)

include_directories(/usr/local/include/cryptopp)
# link_libraries( "/usr/local/lib/libcryptopp.a"　
#                 "/usr/local/lib/libcryptopp.so" 
#                 "/usr/local/lib/libcryptopp.so.8"
#                 "/usr/local/lib/libcryptopp.so.8.7.0")

add_executable( test PrimeGroup.cpp 
                PrimeGroup.hpp 
                test.cpp)

target_link_libraries(test /usr/local/lib/libcryptopp.a)
target_link_libraries(test /usr/local/lib/libcryptopp.so)
target_link_libraries(test /usr/local/lib/libcryptopp.so.8)
target_link_libraries(test /usr/local/lib/libcryptopp.so.8.7.0)