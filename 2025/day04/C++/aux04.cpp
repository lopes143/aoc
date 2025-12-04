#include "day04.hpp"

bool parse_input(vector<vector<char>> &place) {
    ifstream file("../input.txt");
    if (!file) return false;
    string sline;
    while (getline(file,sline)) {
        vector<char> line;
        for (auto ch : sline) line.push_back(ch);
        place.push_back(line);
    }
    return true;
}

vector<char> get_around(const vector<vector<char>> &board, const size_t i, const size_t j) {
    vector<char> out;
    size_t max_i = board.size()-1;
    size_t max_j = board.at(0).size()-1;

    if (i>0) out.push_back(board.at(i-1).at(j));
    if (i<max_i) out.push_back(board.at(i+1).at(j));
    if (j>0) out.push_back(board.at(i).at(j-1));
    if (j<max_j) out.push_back(board.at(i).at(j+1));
    if (i>0 && j>0) out.push_back(board.at(i-1).at(j-1));
    if (i>0 && j<max_j) out.push_back(board.at(i-1).at(j+1));
    if (i<max_i && j>0) out.push_back(board.at(i+1).at(j-1));
    if (i<max_i && j<max_j) out.push_back(board.at(i+1).at(j+1));
    return out;
}

bool roll_accessible(const vector<vector<char>> &board, const size_t i, const size_t j) {
    vector<char> around = get_around(board,i,j);
    uint count {0};
    for (auto ch : around)
        if (ch=='@') count++;
    
    return count<4;
}