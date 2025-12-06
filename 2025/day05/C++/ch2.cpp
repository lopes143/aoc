#include "day05.hpp"

int main() {
    vector<pair<int64,int64>> ranges;
    int64 FreshIDs {0};

    if (!parse_ranges(ranges)) return EXIT_FAILURE;

    //sort ranges
    sort(ranges.begin(), ranges.end(), pair_compare);

    //merge ranges - this algorithm requires the ranges to be sorted
    for (auto i = ranges.begin(); i < ranges.end() - 1; i++) {
        for (auto j = i+1; j < ranges.end(); j++) {
            //if (i) second is greater than (j) first than we can merge
            //-1 because we can merge a range that ends with 19 and the next begins with 20
            if ((*i).second >= (*j).first - 1) {
                //(j) second can be less than (i) if the 2nd range is within the first
                (*i).second = std::max((*i).second, (*j).second);
                ranges.erase(j);
                j--;
            }
            else break;
        }
    }

    for (const auto rng : ranges) {
        FreshIDs+=rng.second-rng.first+1;
    }

    cout << "Fresh ingredient IDs (challenge 2): " << FreshIDs << endl;
    //Right answer:

    return EXIT_SUCCESS;
}