cmake_minimum_required(VERSION 3.10)

project(obj_parser VERSION 1.0)

option(OBJ_PARSER_TESTS "Build obj_parser example programs" ON)

include(GNUInstallDirs)
include(CMakeDependentOption)

add_subdirectory(src)

if (OBJ_PARSER_TESTS)
    add_subdirectory(tests)
endif()
