#include "day08.hpp"

bool parse_input(vector<box> &boxList) {
    ifstream file("../input.txt");

    if (!file) return false;

    int x, y, z;
    char comma;

    string line;
    while (file >> x >> comma >> y >> comma >> z) {
        boxList.emplace_back(x, y, z);
    }

    return true;
}

vector<vector<uint64_t>> compute_distances(vector<box> &boxList) {
    vector<vector<uint64_t>> distances; //distances are squared
    
    for (box b1 : boxList) {
        vector<uint64_t> line;
        for (box b2 : boxList) {
            line.emplace_back( pow(abs(b1.x-b2.x),2) + pow(abs(b1.y-b2.y),2) + pow(abs(b1.z-b2.z),2) );
        }
        distances.push_back(line);
    }

    return distances;
}

vector<pair<size_t, size_t>> sort_distances(vector<vector<uint64_t>> &distances) {
    vector<pair<size_t, size_t>> orderedPairs;
    size_t n = distances.size();

    for (size_t i=0; i<n; i++) {
        for (size_t j=i+1; j<n; j++) {
            orderedPairs.emplace_back(i, j);
        }
    }

    sort(orderedPairs.begin(), orderedPairs.end(), 
        [&distances](const pair<size_t,size_t> &a, const pair<size_t,size_t> &b) {
            return distances[a.first][a.second] < distances[b.first][b.second];
        }
    );

    return orderedPairs;
}

UnionFind::UnionFind(int n) : conections(n) {
    parent.resize(n);
    for (int i=0; i<n; i++) parent[i]=i;

    size.resize(n, 1);
    active.resize(n, false);
}

int UnionFind::find(int i) {
    if (i == parent[i]) return i;
    return parent[i] = find(parent[i]);
}

void UnionFind::union_sets(int x, int y) {
    if (!active[x]) {
        active[x]=true;
        connected++;
    }

    if (!active[y]) {
        active[y]=true;
        connected++;
    }

    int root_x = find(x);
    int root_y = find(y);

    if (root_x == root_y) return;

    if (size[root_x] < size[root_y]) {
        parent[root_x] = root_y;
        size[root_y] += size[root_x];
    }
    else {
        parent[root_y] = root_x;
        size[root_x] += size[root_y];
    }

    conections--;
}

int UnionFind::get_connection_count() {
    return connected;
}

u_int64_t UnionFind::score() {
    u_int64_t out {1};
    vector<int> sortedSize = size;
    sort(sortedSize.begin(), sortedSize.end(),
        [](const int &a, const int &b) {
            return a > b;
        }
    );
    for (int i=0; i<3; i++) { //first 3
        out*=sortedSize[i];
    }
            
    return out;
}

bool UnionFind::all_connected() {
    return conections == 1;
}