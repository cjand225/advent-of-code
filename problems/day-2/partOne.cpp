#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

int main()
{

    // open file
    std::fstream inputFile("input.txt", std::fstream::in);
    std::string inputLine = "";

    // Setup vars for each game.
    int totalSumofPossibleGames, gameID, quantity, red, green, blue = 0;
    std::string color;
    bool addGame = true;

    char *token;
    char *tries;

    // read file & parse it out
    while (std::getline(inputFile, inputLine))
    {
        // convert to a c-string to use strtok
        token = inputLine.data();

        // Split by colon
        token = strtok(token, " :");
        gameID = atoi(strtok(nullptr, " :"));

        std::cout << gameID << std::endl;

        // Copy contents
        tries = new char[strlen(token) + 1];
        strcpy(tries, token);

        // Split based on pulls out of the bag
        tries = strtok(nullptr, ";");

        while (tries != nullptr)
        {
            std::cout << tries << std::endl;

            // Convert to string stream
            std::string cubeSet(tries);
            std::istringstream cubeSetStream(cubeSet);

            // using a different approach here because of strtok implementation has an iternal pointer that keeps moving.
            // Tried copying to a different pointer, but doesn't seem to work as expected.
            while (cubeSetStream >> quantity >> color)
            {
                // Remove any commas as a result from this.
                if (color.back() == ',')
                {
                    color.pop_back();
                }

                std::cout << quantity << color << std::endl;

                if (color == "red")
                {
                    red += quantity;
                }
                else if (color == "blue")
                {
                    blue += quantity;
                }
                else if (color == "green")
                {
                    green += quantity;
                }
            }

            // Output to validate
            std::cout << "gameID: " << gameID << std::endl;
            std::cout << "red: " << red << std::endl;
            std::cout << "blue: " << blue << std::endl;
            std::cout << "green: " << green << std::endl;
            std::cout << std::endl;

            // // Check if it exceeds anything, if it does, skip the game
            if (red > 12 || green > 13 || blue > 14)
            {
                addGame = false;
            }

            // Reset colors
            red = 0;
            blue = 0;
            green = 0;
            quantity = 0;

            // Grab next token
            tries = strtok(nullptr, ";");
        }

        if (addGame)
        {
            std::cout << "gameID Added: " << gameID << std::endl;
            std::cout << std::endl;
            totalSumofPossibleGames += gameID;
        }

        // reset vars
        gameID = 0;
        addGame = true;
        token = nullptr;

        // Clean up Memory
        delete[] tries;

        std::cout << std::endl;
    }

    // Clean up Memory
    delete[] token;

    std::cout << "Sum of total valid games: " << totalSumofPossibleGames << std::endl;
}
