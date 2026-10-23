#include "day08.hpp"

bool parse_input(vector<box> &boxList) {
    ifstream file("../input_test.txt");

    if (!file) return false;

    int x, y, z;
    char comma;

    string line;
    while (file >> x >> comma >> y >> comma >> z) {
        boxList.emplace_back(x, y, z);
    }

    return true;
}