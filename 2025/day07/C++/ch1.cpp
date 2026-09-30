#include "day07.hpp"

int main() {
    vector<vector<int64_t>> board;
    if (!parse_input(board)) return EXIT_FAILURE;

    int64_t splitCount = 0;

    for (size_t i = 1; i < board.size(); i++) {
        for (size_t j = 0; j < board.at(0).size(); j++) {
            int elem = board.at(i).at(j);
            int above = board.at(i-1).at(j);
            if (elem == -1 && above == 1) { //'^'
                //SPLIT
                board.at(i).at(j-1) = 1;
                board.at(i).at(j+1) = 1;
                splitCount++;
            }
            else if (elem == 0 and above > 0) {
                //PROPAGATE
                board.at(i).at(j) = board.at(i-1).at(j);
            }
            else continue;
        }
    }

    cout << "Split count (challenge 1): " << splitCount << endl;
    return EXIT_SUCCESS;
}