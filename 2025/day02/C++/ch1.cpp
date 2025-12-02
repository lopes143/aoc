#include "day02.hpp"

int main() {
    list<pair<uint,uint>> input;
    if (!parse_input(input)) return EXIT_FAILURE;
    unsigned long invalidSum {0};

    for (auto par : input) {
        for (uint i=par.first; i<=par.second; i++) {
            if (test_invalid(i)) invalidSum+=i;
        }
    }

    cout << "Sum of invalid IDs (challenge 1): " << invalidSum << endl;
    //Right answer: 12586854255

    return EXIT_SUCCESS;
}