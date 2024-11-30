# Advent of Code

## Overview

This repository contains my solutions to the [Advent of Code](https://adventofcode.com) challenges, implemented in C++. The Advent of Code is an annual set of Christmas-themed programming puzzles that can be solved in any programming language.

## Structure

The solutions are organized by day within the problems directory for each year. Each day's solutions are further divided into two parts, `partOne.cpp` and `partTwo.cpp`, along with the corresponding input file `input.txt`.

The directory structure is as follows:

```yaml
advent-of-code/
├── year/
│   ├── problems/
│   │   ├── day-1/
│   │   │   ├── partOne.cpp
│   │   │   ├── partTwo.cpp
│   │   │   └── input.txt
│   │   ├── day-2/
│   │   │   ├── partOne.cpp
│   │   │   ├── partTwo.cpp
│   │   │   └── input.txt
│   │   └── ...
```

## Running the Solutions

To run a solution, navigate to the specific day's directory and compile the C++ code. For example:

```sh
cd problems/day-1/
g++ -o solution partOne.cpp --std=c++17
./solution
```

Make sure you have a C++ compiler installed on your system. The solutions are written in standard C++, and no external libraries are required unless specified for each day.
