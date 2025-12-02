#include "day02.hpp"

bool parse_input(list<pair<uint,uint>> &input) {
    ifstream file("../input.txt");
    if (!file) return false;

    uint n1, n2;
    char dash;

    while (file >> n1 >> dash >> n2) {
        input.emplace_back(n1,n2);

        if (file.peek()==',') file.ignore();
    }

    file.close();
    return true;
}

bool test_invalid(const unsigned int &n) {
    int len = log10(n)+1;
    int half = exp10(len/2);
    unsigned int n1 {n/half};
    unsigned int n2 {n%half};

    return n1==n2;
}

bool test_invalid_2(const unsigned int &n) {
    string s = to_string(n);
    uint len = s.length();

    for (int subLen=1; subLen<=len/2; ++subLen) {
        if (len%subLen==0) {
            string pattern = s.substr(0, subLen);
            string builtString = "";
            int repeats = len/subLen;

            for (int i=0; i<repeats; ++i)
                builtString+=pattern;

            if (builtString == s) return true;
        }
    }

    return false;
}