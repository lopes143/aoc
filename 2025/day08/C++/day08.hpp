#ifndef AOC25_DAY08
#define AOC25_DAY08

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdint>
#include <cmath>

using namespace std;

struct box {
    int x, y, z;
};

bool parse_input(vector<box> &boxList);

#endif