#include <stdlib.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

int main() {
    // Read in the file
    std::fstream inputFile("input.txt", std::fstream::in);
    std::string inputString = "";
    std::stringstream ss;

    // Split the line input, left to left list, right to right list
    std::vector<int> leftElements;
    std::vector<int> rightElements;
    std::map<int, int> occurences;
    int left, right;
    while (inputFile >> left >> right) {
        if (occurences.find(left) == occurences.end()) {
            occurences[left] = 0;
        }
        leftElements.push_back(left);
        rightElements.push_back(right);
    }

    // sort both lists
    std::sort(leftElements.begin(), leftElements.end());
    std::sort(rightElements.begin(), rightElements.end());

    int similarity = 0;
    int size = leftElements.size();

    // find out occurences in right list
    for (int i = 0; i < size; i++) {
        occurences[rightElements[i]] += 1;
    }

    // iterate and find similarity score
    for (int i = 0; i < size; i++) {
        similarity += leftElements[i] * occurences[leftElements[i]];
    }

    std::cout << similarity << std::endl;
}
