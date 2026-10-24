#include "day09.hpp"

int main() {
    vector<pair<int, int>> tilesList;
    if (!parse_input(tilesList)) return EXIT_FAILURE;

    vector<tilePair> tilesPairsSorted = compute_sort_areas(tilesList);

    cout << "Largest Rectangle area: " << tilesPairsSorted[0].squareArea << endl;


    return EXIT_SUCCESS;
}