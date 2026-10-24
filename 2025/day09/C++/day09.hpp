#ifndef AOC25_DAY09
#define AOC25_DAY09

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <cmath>
#include <algorithm>

using namespace std;

struct tilePair {
    pair<int,int> x, y;
    uint64_t squareArea;
};

bool parse_input(vector<pair<int,int>> &tilesList);

vector<tilePair> compute_sort_areas(vector<pair<int,int>> &tilesList);

bool parse_input(vector<pair<int,int>> &tilesList, vector<vector<char>> &board);

#endif