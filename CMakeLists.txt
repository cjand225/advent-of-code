cmake_minimum_required(VERSION 3.10)
project(AdventOfCode-Main CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(BUILD_YEARS "" CACHE STRING "Comma-separated list of years to build (e.g., '2023,2024')")

if(BUILD_YEARS STREQUAL "")
    file(GLOB YEAR_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "[0-9][0-9][0-9][0-9]")
    foreach(DIR ${YEAR_DIRS})
        if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${DIR}/problems")
            add_subdirectory(${DIR})
        endif()
    endforeach()
else()
    string(REPLACE "," ";" YEAR_LIST ${BUILD_YEARS})
    foreach(YEAR ${YEAR_LIST})
        if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${YEAR}/problems")
            add_subdirectory(${YEAR})
        else()
            message(STATUS "Year ${YEAR} directory does not exist, skipping...")
        endif()
    endforeach()
endif()
