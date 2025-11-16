#ifndef DEC_05_CPP
#define DEC_05_CPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

bool check_rule_exists(vector<pair<int,int>> &rules, int n1, int n2);

bool check_valid(vector<pair<int,int>> &rules, vector<int> instruction);

#endif