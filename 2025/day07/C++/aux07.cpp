#include "day07.hpp"

bool parse_input(vector<vector<int64_t>> &board) {
    ifstream file("../input.txt");

    if (!file) return false;

    string line;
    while (getline(file,line)) {
        vector<int64_t> line_vec;
        for (char c : line) {
            switch (c) {
                case '^':
                    line_vec.push_back(-1);
                    break;
                case 'S':
                    line_vec.push_back(1); //there's no impact if the S is a beam
                    break;
                case '.':
                default:
                    line_vec.push_back(0);
                    break;
            }
        }
        board.push_back(line_vec);
    }
    return true;
}