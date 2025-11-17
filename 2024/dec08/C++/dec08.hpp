#ifndef DEC_08_CPP
#define DEC_08_CPP

#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

bool parse_input(vector<string> &tab);
bool an_valid(const vector<string> &tab, const pair<int,int> &an);
void put_antinode(const vector<string> &tab, set<pair<int,int>> &ans, const pair<int,int> &s1, const pair<int,int> &s2);
void put_antinode_2(const vector<string> &tab, set<pair<int,int>> &ans, const pair<int,int> &s1, const pair<int,int> &s2);

#endif