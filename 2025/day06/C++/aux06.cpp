#include "day06.hpp"
#include <cctype>

bool parse_input_ch1(vector<vector<uint>> &nums, vector<char> &ops) {
    ifstream file("../input.txt");

    if (!file) return false;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        vector<uint> line_nums;

        while (true) {
            ss >> ws;
            if (ss.eof()) break;

            if (isdigit(ss.peek())) {
                uint num;
                ss >> num;
                line_nums.push_back(num);
            }
            else {
                char op;
                ss >> op;
                ops.push_back(op);
            }
        }
        if (!line_nums.empty()) nums.push_back(line_nums);
    }
    return true;
}

bool parse_input_ch2(vector<vector<char>> &worksheet) {
    ifstream file("../input.txt");

    if (!file) return false;

    string line;
    while (getline(file, line)) {
        vector<char> line_vec;
        for (char c : line) {
            line_vec.push_back(c);
        }
        worksheet.push_back(line_vec);
    }
    return true;
}