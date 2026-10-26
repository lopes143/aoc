#include "dec09.hpp"

bool parse_input(vector<int> &disk) {
    //dots are represented as -1
    char ch;
    int ID = 0;
    bool read_file = true;

    ifstream file("../input_test.txt");
    if (!file) return false;

    while (file.get(ch)) {
        if (read_file) {
            for (int i=0; i<(ch-'0'); i++)
                disk.push_back(ID);
            ID++;
            read_file=false;
        }
        else {
            for (int i=0; i<(ch-'0'); i++)
                disk.push_back(-1);
            read_file=true;
        }
    }

    return true;
}

void print_disk(const vector<int> &disk) { //challenge 1
    for (int i=0; i<disk.size(); i++) {
        char ch {disk.at(i)!=-1 ? disk.at(i)+'0' : '.'};
        cout << ch;
    }
    cout << endl;
}

pair<int,int> find_block_with_ID(vector<int> &disk, int id) {
    pair<int,int> out {-1, -1};
    bool found = false;
    for (size_t i=disk.size(); i>0; i--) {
        if (disk[i-1]==id && !found) {
            out.second = i-1;
            found = true;
        }
        else if (disk[i-1]==-1 && found) {
            out.first = i;
            return out;
        }
    }
    return out;

}

pair<int,int> find_empty_space(vector<int> &disk, int len) {
    pair<int,int> out {-1, -1};
    bool found = false;
    for (size_t i=0; i<disk.size(); i++) {
        if (disk[i]==-1 && !found) {
            out.first = i;
            found = true;
        }
        else if (disk[i]!=-1 && found) {
            out.second = i-1;
            found = false;
            if (out.second-out.first+1 >= len)
                return out;
        }
    }
    return make_pair(-1, -1);
}

void fill_empty_with_block(pair<int,int> &block, pair<int,int> &empty) {
    
}