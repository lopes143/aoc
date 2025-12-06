#ifndef AOC25_DAY05
#define AOC25_DAY05

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdint>
#include <vector>
#include <algorithm>

using namespace std;

typedef uint64_t int64;

bool parse_ranges(vector<pair<int64,int64>> &ranges);
bool parse_ingredients(vector<int64> &ingredients);
bool pair_compare(const pair<int64,int64> &a, const pair<int64,int64> &b);


#endif