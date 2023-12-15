#include <fstream>
#include <iostream>
#include <sstream>
#include <string_view>
#include <set>
#include <map>
#include <queue>

int main()
{
    std::fstream inputFile("input.txt", std::fstream::in);
    std::string inputString = "";

    // Maps to save winning and draw numebers to based on game # for key
    std::map<size_t, std::set<size_t>> wins;
    std::map<size_t, std::set<size_t>> draws;
    std::queue<size_t> gamesToProcess;

    size_t gameID;
    size_t inputNumber;

    size_t totalScratchCards = 0;

    while (std::getline(inputFile, inputString))
    {
        std::string_view inputView(inputString);

        // Find start point of string, find : pos of string - 1, split on white space
        size_t firstSpacePos = inputView.find(" ");
        size_t colonPos = inputView.find(":");
        size_t verticalBarPos = inputView.find("|");
        size_t stringSize = inputView.size();

        std::set<size_t> winningNumbers;
        std::set<size_t> drawNumbers;

        gameID = std::stoi(inputView.substr(firstSpacePos, colonPos - firstSpacePos - 1).data());

        // find : pos of string, Find | part of string, split on white space
        std::istringstream winningStream(inputView.substr(colonPos + 1, verticalBarPos - colonPos - 1).data());

        while (winningStream >> inputNumber)
        {
            winningNumbers.insert(inputNumber);
        }

        // find | part of string, find end of string, split on white space
        std::istringstream drawStream(inputView.substr(verticalBarPos + 1, stringSize - 1).data());
        while (drawStream >> inputNumber)
        {
            drawNumbers.insert(inputNumber);

            // Found initial won games
            if (winningNumbers.find(inputNumber) != winningNumbers.end())
            {
                gamesToProcess.push(inputNumber);

                totalScratchCards += 1;
            }
        }

        wins.insert({gameID, drawNumbers});
        draws.insert({gameID, drawNumbers});
    }

    // swap to queue to continously check nums via maps
    while (!gamesToProcess.empty())
    {
        //
    }
}
