cmake_minimum_required(VERSION 3.10)

project(BasicTest)

set(CMAKE_CXX_STANDARD 11)

add_executable(bt
    ../../String.hpp
    main.cpp
)