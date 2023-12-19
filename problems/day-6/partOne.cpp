#include <fstream>
#include <sstream>
#include <iostream>

int main()
{
    std::fstream inputFile("input.txt", std::fstream::in);
    std::string inputString = "";
    std::string temp;
    size_t length = 4;
    size_t time[length];
    size_t distance[length];

    // Process time
    std::getline(inputFile, inputString);

    std::stringstream iss(inputString);

    iss >> temp >> time[0] >> time[1] >> time[2] >> time[3];

    iss.clear();

    // Process speed
    std::getline(inputFile, inputString);

    iss.str(inputString);

    iss >> temp >> distance[0] >> distance[1] >> distance[2] >> distance[3];

    size_t holdTime = 0;
    size_t timeLeft = 0;
    size_t currentDistance = 0;
    size_t totalRaceNumbers = 1;

    // Iterate over each race
    for (size_t i = 0; i < length; i++)
    {
        size_t numberOfWays = 0;

        for (size_t j = 0; j < time[i]; j++)
        {
            // Calcuate the distance depending on hold time and the time left.
            timeLeft = time[i] - j;
            holdTime = j;
            currentDistance = timeLeft * holdTime;

            // check if distance is greater, if it is - update the numberOfWays
            if (currentDistance > distance[i])
            {
                numberOfWays += 1;
            }
        }

        totalRaceNumbers *= numberOfWays;
    }

    std::cout << totalRaceNumbers << std::endl;
}
