cmake_minimum_required(VERSION 3.28)
project(AutoClicker)

set(CMAKE_CXX_STANDARD 20)

add_executable(AutoClicker Autoclicker.cpp
        Console.cpp
        Console.h)

if (CMAKE_BUILD_TYPE STREQUAL "Custom")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
    add_definitions(-DNDEBUG)
endif()