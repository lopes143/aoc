#include "day04.hpp"

int main() {
    vector<vector<char>> board;
    if (!parse_input(board)) return EXIT_FAILURE;
    unsigned long rollsAccessed {0};
    
    for (size_t i=0; i<board.size(); i++) {
        for (size_t j=0; j<board.at(i).size(); j++) {
            if (board.at(i).at(j)=='@' && roll_accessible(board,i,j))
                rollsAccessed++;
        }
    }

    cout << "Rolls accessed (challenge 1): " << rollsAccessed << endl;
    //Right Answer: 1372

    return EXIT_SUCCESS;
}