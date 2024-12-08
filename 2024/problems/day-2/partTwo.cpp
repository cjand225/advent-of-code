#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool isSequenceSafe(const std::vector<int> &numbers) {
    // Can't be safe if it doesn't have numbers to compare to
    if (numbers.size() < 2) return false;

    bool increasing = false;
    bool decreasing = false;
    for (size_t i = 1; i < numbers.size(); i++) {
        int difference = numbers[i] - numbers[i - 1];
        if (difference == 0 || std::abs(difference) > 3) {
            return false;
        }
        // If an increase or decrease
        if (difference > 0) {
            // Ensure that it hasn't decreased before
            if (decreasing) return false;
            increasing = true;
        } else if (difference < 0) {
            // Ensure that it hasn't increased before
            if (increasing) return false;
            decreasing = true;
        }
    }

    return decreasing || increasing;
}

bool canBeMadeSafe(const std::vector<int> &numbers) {
    if (isSequenceSafe(numbers)) return true;

    for (size_t i = 0; i < numbers.size(); i++) {
        std::vector<int> modifiedNumbers;

        for (size_t j = 0; j < numbers.size(); j++) {
            if (j != i) modifiedNumbers.push_back(numbers[j]);
        }

        if (isSequenceSafe(modifiedNumbers)) return true;
    }

    return false;
}

int main() {
    std::fstream inputFile("input.txt", std::fstream::in);
    std::string inputString = "";

    int safeReports = 0;
    while (std::getline(inputFile, inputString)) {
        std::stringstream inputStream(inputString);
        std::vector<int> numbers;
        int current = 0;

        while (inputStream >> current) {
            numbers.push_back(current);
        }

        if (canBeMadeSafe(numbers)) {
            safeReports++;
        }
    }

    std::cout << safeReports << std::endl;

    return 0;
}
