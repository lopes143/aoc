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

bool parse_input_2(vector<vector<int>> &disk, int &maxID) {
    //dots are still represented as -1
    char ch;
    int ID = 0;
    bool read_file = true;

    ifstream file("../input_test.txt");
    if (!file) return false;
    
    while(file.get(ch)) {
        vector<int> block;
        if (read_file) {
            for (int i=0; i<(ch-'0'); i++)
                block.push_back(ID);
            ID++;
            read_file=false;
        }
        else {
            for (int i=0; i<(ch-'0'); i++)
                block.push_back(-1);
            read_file=true;
        }
        if (block.size()>0)
            disk.push_back(block);
    }

    maxID = ID-1;
    return true;
}

void print_disk(const vector<int> &disk) { //challenge 1
    for (int i=0; i<disk.size(); i++) {
        char ch {disk.at(i)!=-1 ? disk.at(i)+'0' : '.'};
        cout << ch;
    }
    cout << endl;
}

void print_disk_2(const vector<vector<int>> &disk) { //challenge 2
    for (auto elem : disk) {
        char ch {elem.at(0)!=-1 ? static_cast<char>(elem.at(0)+'0') : '.'};
        for (int j=0; j<elem.size(); j++)
            cout << ch;
    }
    cout << endl;
}

//Challenge 2
optional<diskBlock> find_block_with_ID(vector<int> &disk, int &id) {
    diskBlock block;
    bool found=false;
    for (vector<int>::iterator it=disk.end(); it!=disk.begin(); it--) {
        if (*it==id) {
            if (!found) {
                block.right=&*it;
                found=true;
            }
            block.size++;
            block.left=&*it;
        }
        else {
            if (found) return block;
            else continue;
        }
    }
    return nullopt;
}

//Challenge 2
optional<diskBlock> find_empty_space(vector<int> &disk, unsigned int len) {
    diskBlock empty;
    bool emptyFound=false;
    for (vector<int>::iterator it=disk.begin(); it!=disk.end(); it++) {
        if (*it==-1) {
            if (!emptyFound) {
                empty.left=&*it;
                emptyFound=true;
            }
            empty.size++;
            empty.left=&*it;
        }
        else {
            if (emptyFound) {
                emptyFound=false;
                empty.size=0;
            }
            else continue;
        }

        if (empty.size==len)
            return empty;
    }
    return nullopt;
}

// vector<int> find_block_with_ID(const vector<vector<int>> &disk, const int ID) { //challenge 2
//     for (auto elem : disk) {
//         if (elem.at(0)==ID)
//             return elem;
//     }
//     return disk.at(0);
// }

bool check_empty_block(const vector<int> &block) { //challenge 2
    bool empty=true;
    for (auto elem : block)
        if (elem!=-1) empty=false;
    return empty;
}