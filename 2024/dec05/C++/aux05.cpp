#include "dec05.hpp"

using namespace std;

bool check_rule_exists(vector<pair<int,int>> &rules, int n1, int n2) {
    for (auto r : rules)
        if (r.first==n1 && r.second==n2)
            return true;
    return false;
}

bool check_valid(vector<pair<int,int>> &rules, vector<int> instruction) {
    for (unsigned int i=0; i<instruction.size(); i++) { //reference index
        for (unsigned int j=i; j<instruction.size(); j++) { //comparison index
            /* We only need to check for violating rules,
            since a pair of pages may or may not have a rule.
            So, for every pair of pages, we check if there's a rule
            who violates that*/
            if (check_rule_exists(rules,instruction[j],instruction[i]))
                return false;
        }
    }
    return true;
}