#ifndef AOC25_DAY04
#define AOC25_DAY04

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool parse_input(vector<vector<char>> &place);
vector<char> get_around(const vector<vector<char>> &board, const size_t i, const size_t j);
bool roll_accessible(const vector<vector<char>> &board, const size_t i, const size_t j);

#endif