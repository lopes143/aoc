#include "day04.hpp"

int main() {
    vector<vector<char>> board;
    if (!parse_input(board)) return EXIT_FAILURE;
    unsigned long rollsRemoved {0};
    vector<pair<size_t,size_t>> rollsToRemove;
    bool somethingToRemove {true};

    while (somethingToRemove) {
        somethingToRemove=false;

        for (size_t i=0; i<board.size(); i++)
            for (size_t j=0; j<board.at(i).size(); j++)
                if (board.at(i).at(j)=='@' && roll_accessible(board,i,j)) {
                    rollsToRemove.emplace_back(i,j);
                    rollsRemoved++;
                    somethingToRemove=true;
                }
        
        for (auto rolls : rollsToRemove)
            board.at(rolls.first).at(rolls.second)='.';

        rollsToRemove.clear();
    }

    cout << "Rolls removed (challenge 2): " << rollsRemoved << endl;
    //Right Answer: 1372



}