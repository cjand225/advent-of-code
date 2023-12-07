#include <fstream>
#include <iostream>

int main()
{
    // open file
    std::fstream inputFile("input.txt", std::fstream::in);

    // Coincidentally both lines and length of lines are 140.
    const int SIZE = 140;

    // Lets store this in a 2D array of arrays.
    char inputGrid[SIZE][SIZE];

    // We can store this directly since we know the length and width of the input is the same.
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            inputFile.get(inputGrid[i][j]);
        }

        // Ignore new lines characters.
        inputFile.ignore();
    }

    inputFile.close();
}
