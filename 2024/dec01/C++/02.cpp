#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> id1 {};
    vector<int> id2 {};
    int sim {0};

    ifstream file("../input.txt");
    if (!file) return 1;

    int n1, n2;
    while (file >> n1 >> n2) {
        id1.push_back(n1);
        id2.push_back(n2);
    }

    for (int n : id1) {
        int c = count(id2.begin(), id2.end(), n);
        sim += n*c;
    }

    cout << "Similarity score (challenge 2): " << sim << endl;
    //Right answer: 23046913

    return 0;
}