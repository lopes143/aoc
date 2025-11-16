#include "dec06.hpp"

vector<string> parse_input() {
    vector<string> out;
    string line;

    ifstream file("../input.txt");
    if (!file) return out;

    while(getline(file,line))
        out.push_back(line);

    return out;
}

pair<int,int> find_guard(const vector<string> &tab) {
    char guards[] {'^','v','<','>'};

    for (int x=0; x<tab.size(); x++)
        for (int y=0; y<tab.at(x).length(); y++)
            for (char guard: guards)
                if (tab.at(x).at(y)==guard)
                    return make_pair(x,y);
    return make_pair(-1,-1);
}

bool add_pos(set<array<int, 3>> &loopSet, array<int, 3> newPos) {
    for (auto pos: loopSet) {
        if (pos == newPos)
            return false;
    }
    loopSet.insert(newPos);
    return true;
}

bool will_loop(vector<string> tab, const pair<int,int> &guard, int xx, int yy) {
    
    if (tab[xx][yy]=='#') return false; //place cannot already have an obstacle
    tab[xx][yy]='#'; //place the obstacle

    auto pos = guard;
    const int directions[4][2] {{-1,0},{0,1},{1,0},{0,-1}};
    int currentDirection = 0; //'^', 'v', '<', '>'
    set<array<int,3>> loopPlaces;

    //test loop
    while (true) {
        array<int,3> currentPos {pos.first, pos.second, currentDirection};
        if (!add_pos(loopPlaces,currentPos)) {
            //loop found, we'll exit
            return true;
        }

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

    return false;
}