#include "dec06.hpp"

int main() {
    const vector<string> tab = parse_input();
    auto pos = find_guard(tab);

    const int directions[4][2] {{-1,0},{0,1},{1,0},{0,-1}};
    short currentDirection = 0; //'^', 'v', '<', '>'

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

    cout << "Places seen (challenge 1): " << placesSeen.size() << endl;
    //Right answer: 4665

    
    return 0;
}