#include <fstream>
#include <iostream>
#include <sstream>
#include <string_view>
#include <set>

int main()
{
    std::fstream inputFile("input.txt", std::fstream::in);
    std::string inputString = "";
    size_t totalPoints = 0;

    while (std::getline(inputFile, inputString))
    {
        std::string_view inputView(inputString);

        // Find start point of string, find : pos of string - 1, split on white space
        size_t firstSpacePos = inputView.find(" ");
        size_t colonPos = inputView.find(":");
        size_t verticalBarPos = inputView.find("|");
        size_t stringSize = inputView.size();
        std::set<size_t> winningNumbers;

        // find : pos of string, Find | part of string, split on white space
        std::istringstream winningStream(inputView.substr(colonPos + 1, verticalBarPos - colonPos - 1).data());
        size_t number;
        while (winningStream >> number)
        {
            winningNumbers.insert(number);
        }

        // find | part of string, find end of string, split on white space
        std::istringstream drawStream(inputView.substr(verticalBarPos + 1, stringSize - 1).data());
        size_t winningCount = 0;
        while (drawStream >> number)
        {
            // if number in set, its winning number, increase count, otherwise continue.
            if (winningNumbers.find(number) != winningNumbers.end())
            {
                // only if in set
                if (winningCount == 0)
                {
                    winningCount = 1;
                }
                else
                {
                    winningCount *= 2;
                }
            }
        }

        totalPoints += winningCount;
    }

    std::cout << totalPoints << std::endl;
}
