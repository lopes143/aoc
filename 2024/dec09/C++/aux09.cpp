#include "dec09.hpp"

bool parse_input(vector<int> &disk) {
    //dots are represented as -1
    char ch;
    int ID = 0;
    bool read_file = true;

    ifstream file("../input.txt");
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
    for (size_t i=0; i<disk.size(); i++) {
        char ch {disk.at(i)!=-1 ? static_cast<char>(disk.at(i)+'0') : '.'};
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
        else if (disk[i-1]!=id && found) {
            out.first = i;
            return out;
        }
    }
    return out;

}

pair<int,int> find_empty_space(vector<int> &disk, int len) {
    pair<int,int> out {-1, -1};
    int current_size = 0;
    bool found = false;
    for (size_t i=0; i<disk.size(); i++) {
        if (disk[i]==-1) {
            if (!found) {
                out = {i, i};
                found = true;
            }
            else { //found = true
                out.second = i; 
            }
            current_size++;
            if (current_size==len) {
                return out;
            }
        }
        else {
            if (found) {
                found = false;
                current_size=0;
            }
        }
    }
    return make_pair(-1, -1);
}

void fill_empty_with_block(vector<int> &disk, pair<int,int> &block, pair<int,int> &empty) {
    int block_size = block.second-block.first+1;
    int empty_size = empty.second-empty.first+1;
    if (empty_size>=block_size) {
        int block_index = block.second;
        int empty_index = empty.first;
        while (block_index>=block.first && empty_index<=empty.second) {
            swap(disk[block_index], disk[empty_index]);
            block_index--;
            empty_index++;
        }
    }
}