#include "dec08.hpp"

bool parse_input(vector<string> &tab) {
    string line;

    ifstream file("../input.txt");
    if (!file) return false;

    while (getline(file,line))
        tab.push_back(line);
    
    return true;
}

bool an_valid(const vector<string> &tab, const pair<int,int> &an) {
    //anti-node must be inside tab bounds and must not be already an antinode
    if (0<=an.first && an.first<tab.size() && 0<=an.second && an.second<tab.at(0).size())
        return true;
    else
        return false;
}

void put_antinode(const vector<string> &tab, set<pair<int,int>> &ans, const pair<int,int> &s1, const pair<int,int> &s2) {
    /* an1 = 2*(s1) - s2
       an2 = 2*(s2) - s1*/
    pair<int,int> an1 {2*s1.first-s2.first, 2*s1.second-s2.second};
    pair<int,int> an2 {2*s2.first-s1.first, 2*s2.second-s1.second};
    
    if (an_valid(tab, an1)) //put anti-node 1
        ans.insert(an1);

    if (an_valid(tab, an2)) //put anti-node 2
        ans.insert(an2);
}

void put_antinode_2(const vector<string> &tab, set<pair<int,int>> &ans, const pair<int,int> &s1, const pair<int,int> &s2) {
    
    pair<int,int> offset {s2.first-s1.first, s2.second-s1.second};
    pair<int,int> an1 {s1};
    pair<int,int> an2 {s2};

    while (an_valid(tab,an1)) {
        ans.insert(an1);
        an1.first+=offset.first;
        an1.second+=offset.second;
    }
    
    while (an_valid(tab,an2)) {
        ans.insert(an2);
        an2.first-=offset.first;
        an2.second-=offset.second;
    }
}