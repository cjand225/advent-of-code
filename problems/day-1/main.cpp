#include <fstream>
#include <iostream>
#include <map>
#include <string>

int main()
{
    // open file
    std::fstream inputFile("input.txt", std::fstream::in);

    char first, last = '\0';
    int result = 0;
    int sum = 0;

    // read file
    char c;
    while (inputFile.good())
    {

        // read line
        inputFile.get(c);

        // Skip characters that aren't digits or new lines
        if (!isdigit(c) && c != '\n')
        {
            continue;
        }

        // if its a new line, calculate first/last and convert to a real number, reset the "numbers"
        if (c == '\n')
        {
            // concat the result
            sum = (first - '0') * 10 + (last - '0');

            if (sum > 0)
            {
                result += (first - '0') * 10 + (last - '0');
            }

            // reset numbers
            first = '\0';
            last = first;
        }
        // if its a number, update the last digit if the first is already initialized
        else
        {
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
    }

    inputFile.close();

    std::cout << result << std::endl;
}
