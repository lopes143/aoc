#include "dec05.hpp"

using namespace std;

int main() {
    vector<pair<int,int>> rules;
    vector<vector<int>> instructions;
    string line;

    ifstream file_part1("../input_part1.txt");
    ifstream file_part2("../input_part2.txt");
    if (!file_part1 || !file_part2) return 1;

    //parse rules
    while (getline(file_part1, line)) {
        stringstream ss(line);
        int n1,n2;
        char slash;
        if (ss >> n1 >> slash >> n2 && slash == '|') {
            rules.emplace_back(n1,n2);
        }
    }

    //parse instructions
    while (getline(file_part2, line)) {
        stringstream ss(line);
        string number;
        vector<int> line_elems;

        //parse each line element
        while(getline(ss,number,','))
            line_elems.push_back(stoi(number));

        instructions.push_back(line_elems);
    }

    vector<vector<int>> rightInstructions;
    for (auto i : instructions)
        if (check_valid(rules, i))
            rightInstructions.push_back(i);

    int middleCount {0};
    for (auto i : rightInstructions) {
        int middleIndex {static_cast<int>(i.size())/2};
        middleCount+=i.at(middleIndex);
    }
        
    cout << "Middle elements sum (challenge 1): " << middleCount << endl;
    //Right answer: 5747

    return 0;
}