#include "day01.hpp"

int main() {
    list<pair<char,uint>> input;
    int vaultNumber {50};
    uint zeroCount {0};

    if (!parse_input(input)) return EXIT_FAILURE;

    for (auto elem : input) {
        switch (elem.first) {
            case 'R':
                vaultNumber+=elem.second;
                break;
            case 'L':
                vaultNumber+=100-elem.second;
                break;
        }
        while (vaultNumber<0) vaultNumber+=100;
        vaultNumber%=100;

        if (vaultNumber==0) zeroCount++;
    }
    
    cout << "Vault password - zero count (challenge 1): " << zeroCount << endl;
    return EXIT_SUCCESS;
}