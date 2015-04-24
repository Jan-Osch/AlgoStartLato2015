cmake_minimum_required(VERSION 3.1)
project(ALGO)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ALGO.h ALGO.cpp)

set(SOURCE_TEST )
add_executable(ALGO ${SOURCE_FILES} )
add_subdirectory(ScalanieWieluList)
add_subdirectory(ScalanieWieluListTest)
add_subdirectory(ScalanieZbiorow)

