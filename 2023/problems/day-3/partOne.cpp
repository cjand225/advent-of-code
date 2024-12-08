#include <fstream>
#include <iostream>

// Coincidentally both lines and length of lines are 140.
const int SIZE = 140;

int findAdjacency(char (&arr)[SIZE][SIZE], int x, int y) {
    // If valid coordinate or a digit character
    if (x <= (SIZE - 1) && y <= (SIZE - 1) && isdigit(arr[x][y])) {
        // go while till left most digit is found.
        while (isdigit(arr[x][y - 1])) {
            y = y - 1;
        }

        // Start pushing to an a string.
        std::string numberStr;
        while (isdigit(arr[x][y])) {
            numberStr.push_back(arr[x][y]);
            y = y + 1;
        }

        std::cout << numberStr << std::endl;

        return std::stoi(numberStr);
    } else {
        return 0;
    }
}

int main() {
    // open file
    std::fstream inputFile("input.txt", std::fstream::in);

    // Lets store this in a 2D array of arrays.
    char inputGrid[SIZE][SIZE];

    // We can store this directly since we know the length and width of the input is the same.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            inputFile.get(inputGrid[i][j]);
        }

        // Ignore new lines characters.
        inputFile.ignore();
    }

    inputFile.close();

    int partSum = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Check if the current character is a symbol
            if (!isdigit(inputGrid[i][j]) && inputGrid[i][j] != '.') {
                // Check Adjacency && find any numbers
                // Remember edge cases where coordinates may not exist.

                // Adjacency is
                // i - 1, j - 1 -> top left
                partSum += findAdjacency(inputGrid, i - 1, j - 1);

                // i - 1, j     -> top middle
                partSum += findAdjacency(inputGrid, i - 1, j);

                // i - 1, j + 1 -> top right
                partSum += findAdjacency(inputGrid, i - 1, j + 1);

                // i    , j - 1 -> middle left
                partSum += findAdjacency(inputGrid, i, j - 1);

                // i    , j + 1 -> middle right
                partSum += findAdjacency(inputGrid, i, j + 1);

                // i + 1, j - 1 -> bottom left
                partSum += findAdjacency(inputGrid, i + 1, j - 1);

                // i + 1, j     -> bottom middle
                partSum += findAdjacency(inputGrid, i + 1, j);

                // i + 1, j + 1 -> bottom right
                partSum += findAdjacency(inputGrid, i + 1, j + 1);
            }
        }
    }
    std::cout << "Total Sum: " << partSum << std::endl;
}
