#include "dec07.hpp"

size_t concat(size_t a, size_t b) {
    size_t mult=1;

    if (b==0) mult=10;
    else {
        size_t temp_b = b;
        while (temp_b > 0) {
            mult*=10;
            temp_b/=10;
        }
    }

    return static_cast<size_t>(a*mult+b);
}

int main() {
    ifstream file("../input.txt");
    if (!file) return EXIT_FAILURE;

    string line;
    unsigned long totalMatch = 0;

    while(getline(file,line)) {
        size_t match, number;
        vector<vector<size_t>> numbers;
        stringstream lineStream(line);

        lineStream >> match; //get match value
        lineStream.ignore(); //ignore ':'

        while (lineStream >> number) {
            vector<size_t> current;
            if (numbers.size()==0) 
                current.push_back(number);

            else
                for (auto pastNum : numbers[numbers.size()-1]) {
                    current.push_back(pastNum+number);
                    current.push_back(pastNum*number);
                    current.push_back(concat(pastNum,number));
                }

            numbers.push_back(current);
        }

        //find match
        for (auto endNum : numbers[numbers.size()-1]) {
            if (endNum==match) {
                totalMatch+=match;
                break;
            }
        }
    }

    cout << "Elephant Total Calibration Result (challenge 2): " << totalMatch << endl;


    return EXIT_SUCCESS;
}