#include "dec06.hpp"

int main() {
    const vector<string> tab = parse_input();
    pair<int,int> guardPos = find_guard(tab);
    auto pos = guardPos;

    const int directions[4][2] {{-1,0},{0,1},{1,0},{0,-1}};
    int currentDirection = 0; //'^', 'v', '<', '>'

    set<pair<int,int>> placesSeen;

    while (true) {
        placesSeen.insert(pos); //add guard's current position
        int nextX = pos.first + directions[currentDirection][0];
        int nextY = pos.second + directions[currentDirection][1];

        //break if next position is outside board limits
        if (!(nextX >= 0 && nextX < tab.size() && nextY >= 0 && nextY < tab[0].length()))
            break;

        if (tab[nextX][nextY]=='#') {
            currentDirection = (currentDirection + 1) % 4;
        }
        else {
            pos.first = nextX;
            pos.second = nextY;
        }
    }

    int loopCount {0};
    for (auto p : placesSeen) {
        if (p == guardPos)
            //Cannot place obstacle where guard currently is
            continue;
        if (will_loop(tab,guardPos,p.first,p.second))
            loopCount++;
    }

    cout << "Loop count (challenge 2): " << loopCount << endl;
    //Right answer: 1688

}