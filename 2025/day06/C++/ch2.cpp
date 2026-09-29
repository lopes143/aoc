#include "day06.hpp"

int main() {
    vector<vector<char>> worksheet;
    if (!parse_input_ch2(worksheet)) return EXIT_FAILURE;

    uint64 grandTotal = 0;
    vector<uint64> total;
    for (int64 j=worksheet.at(0).size()-1; j>=0; j--) {
        uint64 number = 0;
        for (int64 i=0; i<worksheet.size(); i++) {
            char c = worksheet.at(i).at(j);
            if (i==worksheet.size()-1) { //last char: should be operator
                if (number!=0) total.push_back(number);
                switch (c) {
                    case '+': {
                        uint64 a = 0;
                        for (uint64 i : total) {
                            a += i;
                        }
                        grandTotal += a;
                        total.clear();
                        break;
                    }
                    case '*': {
                        uint64 a = 1;
                        for (uint64 i : total) {
                            a *= i;
                        }
                        grandTotal += a;
                        total.clear();
                        break;
                    }
                    default:
                        break;
                }
            }
            else if (isdigit(c))
                number = number*10 + (c-'0');
        }
    }

    cout << "Grand total after indiv. problems (challenge 2): " << grandTotal << endl;

    return EXIT_SUCCESS;
}