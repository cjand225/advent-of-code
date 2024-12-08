#include <deque>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string_view>

int main() {
    std::fstream inputFile("input.txt", std::fstream::in);
    std::string inputString = "";

    // Maps to save winning and draw numebers to based on game # for key
    std::map<size_t, std::set<size_t>> wins;
    std::deque<size_t> gamesToProcess;
    std::map<size_t, size_t> gamesWon;

    size_t gameID;
    size_t inputNumber;

    size_t totalWins = 0;

    while (std::getline(inputFile, inputString)) {
        std::string_view inputView(inputString);

        // Find start point of string, find : pos of string - 1, split on white space
        size_t firstSpacePos = inputView.find(" ");
        size_t colonPos = inputView.find(":");
        size_t verticalBarPos = inputView.find("|");
        size_t stringSize = inputView.size();

        std::set<size_t> winningNumbers;

        gameID = std::stoi(inputView.substr(firstSpacePos, colonPos - firstSpacePos - 1).data());

        // find : pos of string, Find | part of string, split on white space
        std::istringstream winningStream(inputView.substr(colonPos + 1, verticalBarPos - colonPos - 1).data());

        while (winningStream >> inputNumber) {
            winningNumbers.insert(inputNumber);
        }

        // find | part of string, find end of string, split on white space
        std::istringstream drawStream(inputView.substr(verticalBarPos + 1, stringSize - 1).data());
        while (drawStream >> inputNumber) {
            // if the draw is found in the winning set.
            if (winningNumbers.find(inputNumber) != winningNumbers.end()) {
                gamesToProcess.push_front(inputNumber);

                // Update amount of winning matches for gameID
                if (gamesWon.find(gameID) != gamesWon.end()) {
                    gamesWon[gameID] += 1;
                } else {
                    gamesWon.insert({gameID, 1});
                }
            }
        }
    }

    // Until all matches are complete
    while (!gamesToProcess.empty()) {
        size_t matches = 0;

        // Grab the first game ID.
        gameID = gamesToProcess.front();
        gamesToProcess.pop_front();

        // If id actually matches a real id, process it and the subsequent matches
        if (gamesWon.find(gameID) != gamesWon.end()) {
            matches = gamesWon[gameID];
        }

        for (size_t i = 0; i < matches; i++) {
            totalWins += gamesWon[gameID + i];
        }
    }

    std::cout << totalWins << std::endl;
}
