#include "day06.hpp"

int main() {
    vector<vector<uint>> nums;
    vector<char> ops; //Operators
    if (!parse_input_ch1(nums,ops)) return EXIT_FAILURE;

    uint64 grandTotal {0};

    for (size_t j=0; j<nums.at(0).size(); j++) {
        uint64 total {0};
        for (size_t i=0; i<nums.size(); i++) {
            switch (ops.at(j)) {
                case '+':
                    total+=nums.at(i).at(j);
                    break;
                case '*':
                    if (total==0) total+=1;
                    total*=nums.at(i).at(j);
                    break;
            }
        }
        grandTotal+=total;
    }

    cout << "Grand total solution (challenge 1): " << grandTotal << endl;
    //Right answer:

    return EXIT_SUCCESS;
}