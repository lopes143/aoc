#include "day03.hpp"

int main() {
    vector<vector<uint>> banks;
    unsigned long long score {0};
    if (!parse_input(banks)) return EXIT_FAILURE;

    for (auto row : banks) {
        vector<uint> highest(12,0);
        for (auto elem : row) {
            add_digit(highest,elem);
            for (auto el : highest) {
                cout << el << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
}