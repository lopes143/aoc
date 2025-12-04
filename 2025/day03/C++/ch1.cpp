#include "day03.hpp"

int main() {
    vector<vector<uint>> banks;
    unsigned long score {0};
    if (!parse_input(banks)) return EXIT_FAILURE;
    
    for (auto row : banks) {
        uint highest {0};
        for (size_t i=0; i<row.size(); i++) {
            for (size_t j=i+1; j<row.size(); j++) {
                uint score {row.at(i)*10 + row.at(j)};
                if (score > highest) highest = score;
            }
        }
        score+=highest;
    }

    cout << "Total output joltage (challenge 1): " << score << endl;
    //Right answer:

    return EXIT_SUCCESS;
}