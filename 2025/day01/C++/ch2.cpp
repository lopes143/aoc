#include "day01.hpp"

int main() {
    list<pair<char,uint>> input;
    int vaultNumber {50};
    uint zeroCount {0};

    if (!parse_input(input)) return EXIT_FAILURE;

    for (auto elem : input) {
        switch (elem.first) {
            case 'R':
                for (uint i=0; i<elem.second; i++) {
                    vaultNumber=(vaultNumber+1)%100;
                    if (vaultNumber==0) zeroCount++;
                }
                break;
            case 'L':
                for (uint i=0; i<elem.second; i++) {
                    vaultNumber-=1;
                    if (vaultNumber==0) zeroCount++;
                    else if (vaultNumber<0) vaultNumber+=100;
                }
        }
    }
    
    cout << "Vault password - after password method (challenge 2): " << zeroCount << endl;
    return EXIT_SUCCESS;
}