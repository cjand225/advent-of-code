#include <fstream>
#include <iostream>
#include <map>
#include <string>

int main()
{
    // Create a map of incomplete words.
    std::map<std::string, std::string> incompleteNumberMap = {
        {"eightwo", "eighttwo"}, {"twone", "twoone"}, {"oneight", "oneeight"}};

    // Create a map of words to numbers
    std::map<std::string, int> numberMap = {
        {"eightwo", 82}, {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};

    // open file
    std::fstream inputFile("input.txt", std::fstream::in);

    char first, last = '\0';
    int result = 0;
    std::string inputLine = "";

    // read file
    while (std::getline(inputFile, inputLine))
    {
        // input before replacement
        std::cout << inputLine << std::endl;

        // Replace the broken words
        for (const auto &pair : incompleteNumberMap)
        {
            std::string word = pair.first;
            std::string number = pair.second;

            // Have to while loop it as it could have more than 1 of the same occurence.
            size_t pos = inputLine.find(word);
            while (pos != std::string::npos)
            {
                inputLine.replace(pos, word.length(), number);
                pos = inputLine.find(word, pos + number.length());
            }
        }

        // word replacement with mapping
        for (const auto &pair : numberMap)
        {
            std::string word = pair.first;
            std::string number = std::to_string(pair.second);

            // Have to while loop it as it could have more than 1 of the same occurence.
            size_t pos = inputLine.find(word);
            while (pos != std::string::npos)
            {
                inputLine.replace(pos, word.length(), number);
                pos = inputLine.find(word, pos + number.length());
            }
        }

        // input after replacement
        std::cout << inputLine << std::endl;

        // Iterate through each line
        for (char c : inputLine)
        {

            // Skip characters that aren't digits or new lines
            if (!isdigit(c))
            {
                continue;
            }

            // Case where characters haven't been set or new line is encounted
            if (first == '\0')
            {
                first = c;
                last = first;
            }
            else
            {
                last = c;
            }
        }

        result += (first - '0') * 10 + (last - '0');

        // result from the line
        std::cout << (first - '0') * 10 + (last - '0') << std::endl;

        // reset numbers
        first = '\0';
        last = first;
    }

    inputFile.close();

    std::cout << result << std::endl;
}
