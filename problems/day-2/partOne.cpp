#include <fstream>
#include <map>
#include <iostream>

int main()
{

    // open file
    std::fstream inputFile("input.txt", std::fstream::in);
    std::string inputLine = "";

    // Setup vars for getting counts for each game.
    int totalSumofPossibleGames = 0;
    int gameID = 0;
    int red = 0;
    int blue = 0;
    int green = 0;
    int quantity = 0;

    char *cstr;
    char *token;

    // read file & parse it out
    while (std::getline(inputFile, inputLine))
    {
        // convert to a c-string to use strtok
        cstr = inputLine.data();

        // Split by colon
        token = strtok(cstr, ": ");
        token = strtok(nullptr, ": ");
        gameID = atoi(token);

        // Grab right side of string
        token = strtok(nullptr, ":");

        // Split based on qty/color
        token = strtok(token, " ");

        while (token != nullptr)
        {
            // if not, check if its red/blue/green, add the quantity to the red, blue, green vars
            if (strcmp("red", token) == 0)
            {
                red += quantity;
            }
            else if (strcmp("blue", token) == 0)
            {
                blue += quantity;
            }
            else if (strcmp("green", token) == 0)
            {
                green += quantity;
            }
            else
            {
                quantity = atoi(token);
            }

            // Grab next token
            token = strtok(nullptr, " ,;");
        }

        // Output to validate
        std::cout << "gameID: " << gameID << std::endl;
        std::cout << "red: " << red << std::endl;
        std::cout << "blue: " << blue << std::endl;
        std::cout << "green: " << green << std::endl;
        std::cout << std::endl;

        // doesn't exceed 12 red cubes, 13 green cubes, and 14 blue cubes in the current game ID.
        if (red <= 12 && green <= 13 && blue <= 14)
        {
            std::cout << "gameID Added: " << gameID << std::endl;
            std::cout << std::endl;
            totalSumofPossibleGames += gameID;
        }

        // reset vars
        gameID = 0;
        red = 0;
        blue = 0;
        green = 0;
        token = nullptr;
    }

    std::cout << "Sum of total valid games: " << totalSumofPossibleGames << std::endl;
}
