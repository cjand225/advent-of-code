cmake_minimum_required(VERSION 3.10)
project(AOC-2023-Problems CXX)

set(BUILD_DAYS "" CACHE STRING "Comma-separated list of days to build (e.g., '1,2,3')")

function(add_day_problems YEAR DAY)
    set(DAY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/day-${DAY}")
    if(NOT EXISTS "${DAY_DIR}")
        message(STATUS "Day ${DAY} directory does not exist, skipping...")
        return()
    endif()

    set(PART1_FILE "${DAY_DIR}/partOne.cpp")
    set(PART2_FILE "${DAY_DIR}/partTwo.cpp")
    set(INPUT_FILE "${DAY_DIR}/input.txt")

    # Set output directory for this day
    set(DAY_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/day-${DAY}")

    # Only build part 1 if it exists
    if(EXISTS "${PART1_FILE}")
        add_executable(${YEAR}_day${DAY}_part1 "${PART1_FILE}")
        set_target_properties(${YEAR}_day${DAY}_part1 PROPERTIES
            OUTPUT_NAME "${YEAR}_day${DAY}_part1"
            VS_DEBUGGER_WORKING_DIRECTORY "${DAY_DIR}"
            RUNTIME_OUTPUT_DIRECTORY "${DAY_BUILD_DIR}"
        )
        # Copy input file to build directory for part 1
        if(EXISTS "${INPUT_FILE}")
            add_custom_command(
                TARGET ${YEAR}_day${DAY}_part1 PRE_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                ${DAY_BUILD_DIR}
            )
            add_custom_command(
                TARGET ${YEAR}_day${DAY}_part1 POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${INPUT_FILE}
                ${DAY_BUILD_DIR}/input.txt
            )
        endif()
        message(STATUS "Adding ${YEAR} Day ${DAY} Part 1")
    endif()

    # Only build part 2 if it exists
    if(EXISTS "${PART2_FILE}")
        add_executable(${YEAR}_day${DAY}_part2 "${PART2_FILE}")
        set_target_properties(${YEAR}_day${DAY}_part2 PROPERTIES
            OUTPUT_NAME "${YEAR}_day${DAY}_part2"
            VS_DEBUGGER_WORKING_DIRECTORY "${DAY_DIR}"
            RUNTIME_OUTPUT_DIRECTORY "${DAY_BUILD_DIR}"
        )
        # Copy input file to build directory for part 2
        if(EXISTS "${INPUT_FILE}")
            add_custom_command(
                TARGET ${YEAR}_day${DAY}_part2 PRE_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                ${DAY_BUILD_DIR}
            )
            add_custom_command(
                TARGET ${YEAR}_day${DAY}_part2 POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${INPUT_FILE}
                ${DAY_BUILD_DIR}/input.txt
            )
        endif()
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
