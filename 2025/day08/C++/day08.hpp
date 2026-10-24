#ifndef AOC25_DAY08
#define AOC25_DAY08

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdint>
#include <cmath>
#include <algorithm>

using namespace std;

struct box {
    int x, y, z;
};

bool parse_input(vector<box> &boxList);

vector<vector<uint64_t>> compute_distances(vector<box> &boxList);

vector<pair<size_t, size_t>> sort_distances(vector<vector<uint64_t>> &distances);

class UnionFind {
    vector<int> parent, size;
    vector<bool> active;
    int connected {0};
    int conections;

public:
    UnionFind(int n);

    int find(int i);
    void union_sets(int x, int y);
    int get_connection_count();
    u_int64_t score();
    bool all_connected();
};

#endif