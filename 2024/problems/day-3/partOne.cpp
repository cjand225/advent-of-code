#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

enum class State {
    M,
    U,
    L,
    OPEN_PAREN,
    FIRST_NUMBER,
    SECOND_NUMBER,
};

int main() {
    std::ifstream inputFile("input.txt");
    std::string inputString;

    long totalSum = 0;

    while (std::getline(inputFile, inputString)) {
        State state = State::M;

        int first = 0;
        int second = 0;
        long result = 0;

        std::string number = "";

        // Iterate char by char and determine state based on current char
        for (char c : inputString) {
            switch (state) {
                case State::M:
                    if (c == 'm') state = State::U;

                    number = "";
                    break;
                case State::U:
                    if (c == 'u')
                        state = State::L;
                    else
                        state = State::M;
                    break;
                case State::L:
                    if (c == 'l')
                        state = State::OPEN_PAREN;
                    else
                        state = State::M;
                    break;
                case State::OPEN_PAREN:
                    if (c == '(')
                        state = State::FIRST_NUMBER;
                    else
                        state = State::M;
                    break;
                case State::FIRST_NUMBER:
                    if (c >= '0' && c <= '9') {
                        if (number.length() < 3) {
                            number += c;
                        } else {
                            number = "";
                            state = State::M;
                        }
                    } else if (c == ',' && !number.empty()) {
                        first = std::atoi(number.c_str());
                        number = "";
                        state = State::SECOND_NUMBER;
                    } else {
                        state = State::M;
                        number = "";
                    }
                    break;
                case State::SECOND_NUMBER:
                    if (c >= '0' && c <= '9') {
                        if (number.length() < 3) {
                            number += c;
                        } else {
                            number = "";
                            state = State::M;
                        }
                    } else if (c == ')' && !number.empty()) {
                        second = std::atoi(number.c_str());
                        result = first * second;
                        totalSum += result;
                        number = "";
                        state = State::M;
                    } else {
                        state = State::M;
                        number = "";
                    }
                    break;
                default:
                    break;
            }
        }
    }

    std::cout << totalSum << std::endl;

    return 0;
}
