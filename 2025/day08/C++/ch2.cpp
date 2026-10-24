#include "day08.hpp"

int main() {

    vector<box> boxList;
    if (!parse_input(boxList)) return EXIT_FAILURE;

    vector<vector<uint64_t>> boxDistances = compute_distances(boxList);
    vector<pair<size_t,size_t>> sortedDistances = sort_distances(boxDistances);
    int boxCount = boxList.size();
    uint64_t out {0};

    UnionFind uf(boxCount);
    for (auto d : sortedDistances) {
        uf.union_sets(d.first, d.second);
        if (uf.all_connected()) {
            uint64_t a = boxList[d.first].x;
            uint64_t b = boxList[d.second].x;
            out = a * b;
            break;
        }
    }

    cout << "Multiply X coordinates (challenge 2): " << out << endl;

    return EXIT_SUCCESS;
}