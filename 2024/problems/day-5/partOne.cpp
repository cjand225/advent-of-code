#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

class Graph {
    std::unordered_map<int, std::vector<int>> adj;

   public:
    void addEdge(int from, int to) {
        adj[from].push_back(to);
    }

    bool isValidOrder(const std::vector<int>& update) {
        for (size_t i = 0; i < update.size(); i++) {
            for (size_t j = i + 1; j < update.size(); j++) {
                int curr = update[i];
                int next = update[j];

                if (adj.count(next)) {
                    auto& deps = adj[next];
                    if (std::find(deps.begin(), deps.end(), curr) != deps.end()) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

std::string readFile(const std::string& filename) {
    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main() {
    std::string inputFile = readFile("input.txt");
    std::istringstream iss(inputFile);
    std::string line;
    Graph g;

    bool firstPartFinished = false;
    std::vector<std::vector<int>> updates;

    while (std::getline(iss, line)) {
        if (line.empty()) {
            firstPartFinished = true;
            continue;
        }

        if (!firstPartFinished) {
            size_t pos = line.find('|');
            int from = std::stoi(line.substr(0, pos));
            int to = std::stoi(line.substr(pos + 1, line.length() - 1));
            g.addEdge(from, to);
        } else {
            std::vector<int> update;
            std::istringstream numStream(line);
            std::string num;
            while (std::getline(numStream, num, ',')) {
                update.push_back(std::stoi(num));
            }
            updates.push_back(update);
        }
    }

    int sum = 0;
    for (const auto& update : updates) {
        if (g.isValidOrder(update)) {
            sum += update[update.size() / 2];
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
