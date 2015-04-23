cmake_minimum_required(VERSION 3.1)
project(ALGO)

ADD_SUBDIRECTORY (gtest-1.7.0)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

enable_testing()

set(SOURCE_FILES
    ScalanieListTest.h
    ScalanieListTest.cpp
    )

add_executable(ScalanieWieluListTest ${SOURCE_FILES} )
target_link_libraries(ScalanieWieluListTest gtest gtest_main)
add_test( ScalanieWieluListTest runUnitTests )