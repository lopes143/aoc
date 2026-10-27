#ifndef DEC_09_CPP
#define DEC_09_CPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool parse_input(vector<int> &disk);
void print_disk(const vector<int> &disk);
pair<int,int> find_block_with_ID(vector<int> &disk, int id);
pair<int,int> find_empty_space(vector<int> &disk, int len);
void fill_empty_with_block(vector<int> &disk, pair<int,int> &block, pair<int,int> &empty);

#endif