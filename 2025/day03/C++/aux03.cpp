#include "day03.hpp"


bool parse_input(vector<vector<uint>> &input) {
    ifstream file("../input.txt");
    if (!file) return false;
    string line;

    while (getline(file,line)) {
        vector<uint> row;
        for (auto ch : line) row.push_back(atoi(&ch));
        input.push_back(row);
    }
    return true;
}

void add_digit(vector<uint> &target, uint num) {
    uint size {0};
    for (size_t i=0; i<target.size(); i++) {
        if (target.at(i)==0) break;
        size=i;
    }

    for (size_t i=size-1; i>=0; i--) {
        if (target.at(i)<num) {
            target.at(i)=num;
            for (size_t j=i; j<size; j++) target.at(j)=0;
        }
    }
}