cmake_minimum_required(VERSION 3.1)
project(ALGO)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Nawiasy.cpp

    )

set(SOURCE_TEST )
add_executable(Nawiasy.cpp ${SOURCE_FILES} )

