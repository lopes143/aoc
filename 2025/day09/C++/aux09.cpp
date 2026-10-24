#include "day09.hpp"

bool parse_input(vector<pair<int,int>> &tilesList) {
    ifstream file("../input.txt");
    if (!file) return false;

    int x, y;
    char comma;
    while (file >> x >> comma >> y) {
        tilesList.emplace_back(y, x);
    }

    return true;
}

vector<vector<char>> make_board(vector<pair<int,int>> &tilesList) {
    vector<vector<char>> board;
    
}

vector<tilePair> compute_sort_areas(vector<pair<int,int>> &tilesList) {
    vector<tilePair> out;
    for (size_t i=0; i<tilesList.size(); i++) {
        for (size_t j=i+1; j<tilesList.size(); j++) {
            tilePair pair;
            pair.x = tilesList[i];
            pair.y = tilesList[j];
            uint64_t width  = static_cast<uint64_t>(abs(pair.x.first  - pair.y.first))  + 1;
            uint64_t height = static_cast<uint64_t>(abs(pair.x.second - pair.y.second)) + 1;
            pair.squareArea = width * height;
            out.emplace_back(pair);
        }
    }

    sort(out.begin(), out.end(),
        [](const tilePair &a, const tilePair &b) {
            return a.squareArea > b.squareArea;
        }
    );

    return out;
}