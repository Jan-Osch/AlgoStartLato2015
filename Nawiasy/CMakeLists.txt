cmake_minimum_required(VERSION 3.1)
project(ALGO)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    ScalanieList.cpp

    )

set(SOURCE_TEST )
add_executable(ScalanieWieluList ${SOURCE_FILES})

