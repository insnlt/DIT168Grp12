cmake_minimum_required(VERSION 3.2)

find_package(libcluon REQUIRED)
include_directories(SYSTEM ${CLUON_INCLUDE_DIRS})

add_subdirectory(src/)
