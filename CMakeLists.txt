cmake_minimum_required(VERSION 3.10)

project(obj_parser VERSION 1.0)

option(OBJ_PARSER_TESTS "Build obj_parser example programs" ON)

include(GNUInstallDirs)
include(CMakeDependentOption)

add_subdirectory(src)

if (OBJ_PARSER_TESTS)
    add_subdirectory(tests)
endif()

if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
endif()
