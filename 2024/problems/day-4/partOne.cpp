#include <fstream>
#include <iostream>
#include <string>
#include <vector>

const int directionX[] = {1, -1, 0, 0, 1, -1, 1, -1};  // right, left, 0, 0, right, left, right, left
const int directionY[] = {0, 0, 1, -1, 1, 1, -1, -1};  // 0, 0, down, up, down, down, up, up

bool isValid(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

bool checkXMAS(const std::vector<std::vector<char>>& grid, int x, int y, int dir) {
    const std::string target = "XMAS";
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < 4; i++) {
        int newX = x + i * directionX[dir];
        int newY = y + i * directionY[dir];

        if (!isValid(newX, newY, rows, cols) || grid[newX][newY] != target[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ifstream file("input.txt");
    std::string line;
    std::vector<std::vector<char>> grid;

    // Read input into grid
    while (std::getline(file, line)) {
        std::vector<char> row;
        for (char c : line) {
            row.push_back(c);
        }
        grid.push_back(row);
    }

    int count = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    // Check each position
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // check all 8 directions
            for (int dir = 0; dir < 8; dir++) {
                if (checkXMAS(grid, i, j, dir)) {
                    count++;
                }
            }
        }
    }

    std::cout << count << std::endl;
    return 0;
}
