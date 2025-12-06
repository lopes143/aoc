#include "day05.hpp"

bool parse_ranges(vector<pair<int64,int64>> &ranges) {
    ifstream file1("../input1.txt");
    
    if (!file1) return false;

    string line;
    while (getline(file1,line)) {
        stringstream ss(line);
        int64 n1,n2;
        char dash;
        ss >> n1 >> dash >> n2;
        ranges.emplace_back(n1,n2);
    }

    return true;
}

bool parse_ingredients(vector<int64> &ingredients) {
    ifstream file2("../input2.txt");
    if (!file2) return false;

    string line;
    while (getline(file2,line)) {
        stringstream ss(line);
        int64 n1;
        ss >> n1;
        ingredients.emplace_back(n1);
    }

    return true;
}


bool pair_compare(const pair<int64,int64> &a, const pair<int64,int64> &b) {
    if (a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}