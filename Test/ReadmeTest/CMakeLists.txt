cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 11)

project(ReadmeTest)

include_directories(../../)

add_executable(rt
    ../../String.hpp
    main.cpp
)