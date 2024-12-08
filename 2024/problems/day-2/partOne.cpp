#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::fstream inputFile("input.txt", std::fstream::in);
    std::string inputString = "";

    int safeReports = 0;
    while (std::getline(inputFile, inputString)) {
        std::stringstream inputStream(inputString);

        int current = -1;
        int previous = -1;
        bool safe = true;
        int increases = 0;
        int decreases = 0;

        // Sliding window approach
        while (inputStream >> current) {
            // We effectively wanna skip the initial case
            if (previous == -1) {
                previous = current;
                continue;
            }

            int difference = current - previous;
            // if abs(current - previous) <= 3 or not 0 - Good
            if (difference == 0 || std::abs(difference) > 3) {
                safe = false;
                break;
            }

            // If an increase
            if (difference > 0) {
                // Ensure that it hasn't decreased before
                if (decreases > 0) {
                    safe = false;
                    break;
                }

                increases++;

                // if an decrease
            } else if (difference < 0) {
                // Ensure that it hasn't increased before
                if (increases > 0) {
                    safe = false;
                    break;
                }
                decreases++;
            }

            // Assign previous to current
            previous = current;
        }

        if (safe && (increases > 0 || decreases > 0)) {
            safeReports++;
        }
    }

    std::cout << safeReports << std::endl;

    return 0;
}
