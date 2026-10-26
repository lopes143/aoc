#ifndef DEC_09_CPP
#define DEC_09_CPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;



bool parse_input(vector<int> &disk);
void print_disk(const vector<int> &disk);
optional<diskBlock> find_block_with_ID_old(vector<int> &disk, int &id);
optional<diskBlock> find_empty_space_old(vector<int> &disk, unsigned int len);
bool check_empty_block(const vector<int> &block);

#endif
