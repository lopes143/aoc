#include "day01.hpp"

bool parse_input(list<pair<char,uint>> &orders) {
    char ch;
    uint i;
    string line;

    ifstream file("../input.txt");
    if (!file) return false;

    while (getline(file, line)) {
        stringstream ls(line);
        ls >> ch >> i;
        orders.emplace_back(ch,i);
    }

    file.close();
    return true;
}