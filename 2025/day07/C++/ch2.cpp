#include "day07.hpp"

int main() {
    vector<vector<int64_t>> board;
    if (!parse_input(board)) return EXIT_FAILURE;

    uint64_t pathCount = 0;

    for (size_t i = 1; i < board.size(); i++) {
        for (size_t j = 0; j < board.at(0).size(); j++) {
            int64_t elem = board.at(i).at(j);
            int64_t above = board.at(i-1).at(j);
            if (elem == -1 && above > 0) { //'^'
                //SPLIT
                board.at(i).at(j-1) += above;
                board.at(i).at(j+1) += above;
            }
            else if (elem >= 0 && above > 0) {
                //PROPAGATE
                board.at(i).at(j) += above;
            }
            else continue;
        }
    }

    //Count paths
    for (size_t j = 0; j < board.at(0).size(); j++) {
        int64_t elem = board.at(board.size()-1).at(j);
        if (elem>0) pathCount+=elem;
    }

    cout << "Split count (challenge 2): " << pathCount << endl;
    return EXIT_SUCCESS;
}