#include "dec07.hpp"

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

    cout << "Total Calibration Result (challenge 1): " << totalMatch << endl;
    //Right answer: 20665830408335


    return EXIT_SUCCESS;
}