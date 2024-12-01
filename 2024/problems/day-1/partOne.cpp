#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
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
  int left, right;
  while (inputFile >> left >> right) {
    leftElements.push_back(left);
    rightElements.push_back(right);
  }

  std::sort(leftElements.begin(), leftElements.end());
  std::sort(rightElements.begin(), rightElements.end());
  // sort both lists
  // iterate over all lists
  int distance = 0;
  int size = 0;

  // subtract each iteration and add it to the distance.
  if (leftElements.size() > rightElements.size()) {
    size = leftElements.size();
  } else {
    size = rightElements.size();
  }

  for (int i = 0; i < size; i++) {
    distance += abs(leftElements[i] - rightElements[i]);
  }

  std::cout << distance << std::endl;
}
