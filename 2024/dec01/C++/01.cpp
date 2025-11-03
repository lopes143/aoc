#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> id1 {};
    vector<int> id2 {};
    int totalDist {0};

    ifstream file("../input.txt");
    if (!file) return 1;

    int n1, n2;
    while (file >> n1 >> n2) {
        id1.push_back(n1);
        id2.push_back(n2);
    }

    sort(id1.begin(), id1.end());
    sort(id2.begin(), id2.end());

    for (size_t i {0}; i<id1.size(); i++) {
        totalDist+=abs(id1[i]-id2[i]);
    }

    cout << "Total Distance (challenge 1): " << totalDist << endl;
    //Right answer: 1580061

    return 0;
}