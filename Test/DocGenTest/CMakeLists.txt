cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 11)

project(DocGenTest)

include_directories(../../)

add_executable(doc
    ../../String.hpp
    main.cpp
)