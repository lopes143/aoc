#include "day08.hpp"

int main() {
    vector<box> boxList;
    if (!parse_input(boxList)) return EXIT_FAILURE;

    vector<vector<uint64_t>> boxDistances = compute_distances(boxList);
    vector<pair<size_t,size_t>> sortedDistances = sort_distances(boxDistances);
    int boxCount = boxList.size();
    int count {1000};

    UnionFind uf(boxCount);
    for (auto d : sortedDistances) {
        if (uf.get_connection_count() < boxCount && count > 0) {
            uf.union_sets(d.first, d.second);
            count--;
        }
        else break;
    }

    cout << "Multiply of largest 3 circuits (challenge 1): " << uf.score() << endl;

    return EXIT_SUCCESS;
}