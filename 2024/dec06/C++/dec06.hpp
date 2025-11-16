#ifndef DEC_06_CPP
#define DEC_06_CPP

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <set>
#include <array>

using namespace std;

struct loopPos {
    int x;
    int y;
    short dir;
};

vector<string> parse_input();

pair<int,int> find_guard(const vector<string> &tab);

bool set_contains_pos(const set<loopPos> &loopSet, int x, int y, int dir);

bool will_loop(vector<string> tab, const pair<int,int> &guard, int xx, int yy);

#endif