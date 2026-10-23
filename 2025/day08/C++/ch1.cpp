#include "day08.hpp"

vector<vector<double>> compute_distances(vector<box> &boxList) {
    vector<vector<double>> distances;
    
    for (box b1 : boxList) {
        vector<double> line;
        for (box b2 : boxList) {
            line.emplace_back(sqrt(static_cast<double>((b1.x-b2.x)^2 + (b1.y-b2.y)^2 + (b1.z-b2.z)^2)));
        }
        distances.push_back(line);
    }

    return distances;
}

optional<pair<int,int>> pick_closest(vector<vector<double>> &distances) {

    double min = INFINITY;
    pair<int,int> coordinates {-1, -1};
    for (size_t i=0; i<distances.size(); i++) {
        for (size_t j = 0; j< distances.at(0).size(); j++) {
            double val = distances.at(i).at(j);
            if (val != 0 && val < min) {
                min = val;
                coordinates = {i, j};
            }
        }
    }

    if (coordinates.first==-1) return nullopt;
    else return coordinates;
}

int main() {
    vector<box> boxList;
    if (!parse_input(boxList)) return EXIT_FAILURE;

    vector<vector<double>> boxDistance = compute_distances(boxList);

    vector<vector<box>> connections;
    while (true) {
        auto small = pick_closest(boxDistance);
        if (!small.has_value()) {
            break;
        }

        
    }

    return EXIT_SUCCESS;
}