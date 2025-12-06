#include "day05.hpp"

int main() {
    vector<pair<int64,int64>> ranges;
    vector<int64> ingredients;
    if (!parse_ranges(ranges) || !parse_ingredients(ingredients)) return EXIT_FAILURE;

    int64 freshCount {0};

    for (const auto ingr : ingredients) {
        bool fresh = false;
        for (const auto range : ranges)
            if (range.first<=ingr && ingr<=range.second) {
                fresh=true;
                break;
            }

        if (fresh) freshCount++;
    }

    cout << "Fresh ingredients (challenge 1): " << freshCount << endl;
    //Right answer: 726


    return EXIT_SUCCESS;
}