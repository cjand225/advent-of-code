cmake_minimum_required(VERSION 3.10)
project(AOC-2024-Problems CXX)

set(BUILD_DAYS "" CACHE STRING "Comma-separated list of days to build (e.g., '1,2,3')")

function(add_day_problems YEAR DAY)
    set(DAY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/day-${DAY}")
    if(NOT EXISTS "${DAY_DIR}")
        message(STATUS "Day ${DAY} directory does not exist, skipping...")
        return()
    endif()

    set(PART1_FILE "${DAY_DIR}/partOne.cpp")
    set(PART2_FILE "${DAY_DIR}/partTwo.cpp")

    # Only build part 1 if it exists
    if(EXISTS "${PART1_FILE}")
        add_executable(${YEAR}_day${DAY}_part1 "${PART1_FILE}")
        set_target_properties(${YEAR}_day${DAY}_part1 PROPERTIES
            OUTPUT_NAME "${YEAR}_day${DAY}_part1"
            VS_DEBUGGER_WORKING_DIRECTORY "${DAY_DIR}"
        )
        message(STATUS "Adding ${YEAR} Day ${DAY} Part 1")
    endif()

    # Only build part 2 if it exists
    if(EXISTS "${PART2_FILE}")
        add_executable(${YEAR}_day${DAY}_part2 "${PART2_FILE}")
        set_target_properties(${YEAR}_day${DAY}_part2 PROPERTIES
            OUTPUT_NAME "${YEAR}_day${DAY}_part2"
            VS_DEBUGGER_WORKING_DIRECTORY "${DAY_DIR}"
        )
        message(STATUS "Adding ${YEAR} Day ${DAY} Part 2")
    endif()
endfunction()

if(BUILD_DAYS STREQUAL "")
    file(GLOB DAY_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "day-*")
    foreach(DIR ${DAY_DIRS})
        if(DIR MATCHES "day-([0-9]+)")
            add_day_problems(${PROJECT_NAME} ${CMAKE_MATCH_1})
        endif()
    endforeach()
else()
    string(REPLACE "," ";" DAY_LIST ${BUILD_DAYS})
    foreach(DAY ${DAY_LIST})
        add_day_problems(${PROJECT_NAME} ${DAY})
    endforeach()
endif()
