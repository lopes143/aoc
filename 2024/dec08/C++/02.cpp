#include "dec08.hpp"

int main() {
    vector<string> tab;
    set<pair<int,int>> anti_nodes;
    if (!parse_input(tab)) return EXIT_FAILURE;

    for (int i=0; i<tab.size(); i++)
            for (int j=0; j<tab.at(i).size(); j++)
                if (tab.at(i).at(j)!='.') //if position has an antenna

                    for (int i2=0; i2<tab.size(); i2++) 
                        for (int j2=0; j2<tab.at(i2).size(); j2++) 
                            if (i!=i2 && j!=j2 && tab.at(i).at(j)==tab.at(i2).at(j2)) {
                                //if 2nd position is the same type but different position from the 1st

                                pair<int,int> s1 {i,j};
                                pair<int,int> s2 {i2,j2};
                                put_antinode_2(tab,anti_nodes,s1,s2);
                            }
    
    cout << "Anti-node count with harmonics (challenge 2): " << anti_nodes.size() << endl;
    //Right answer: 809

    return EXIT_SUCCESS;
}