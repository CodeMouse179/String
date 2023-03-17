cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 11)

project(BasicTest)

include_directories(../../)

add_executable(bt
    ../../String.hpp
    main.cpp
)