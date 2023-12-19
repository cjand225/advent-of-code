#include <fstream>
#include <sstream>
#include <iostream>

int main()
{
    std::fstream inputFile("input.txt", std::fstream::in);
    std::string inputString = "";
    std::string temp;

    std::string numString = "";
    int number;

    size_t time;
    size_t distance;

    // Process time
    std::getline(inputFile, inputString);

    std::stringstream iss(inputString);

    iss >> temp;

    for (size_t i; i < 4; i++)
    {
        iss >> number;
        numString += std::to_string(number);
    }

    time = std::stol(numString);

    // Reset vars before processing speed
    numString = "";
    iss.clear();

    // Process speed
    std::getline(inputFile, inputString);

    iss.str(inputString);

    iss >> temp;

    for (size_t i; i < 4; i++)
    {
        iss >> number;
        numString += std::to_string(number);
    }

    distance = std::stol(numString);

    // Setup for processing ways.
    size_t holdTime = 0;
    size_t timeLeft = 0;
    size_t currentDistance = 0;
    size_t numberOfWays = 0;

    for (size_t j = 0; j < time; j++)
    {
        // Calcuate the distance depending on hold time and the time left.
        timeLeft = time - j;
        holdTime = j;
        currentDistance = timeLeft * holdTime;

        // check if distance is greater, if it is - update the numberOfWays
        if (currentDistance > distance)
        {
            numberOfWays += 1;
        }
    }

    std::cout << numberOfWays << std::endl;
}
