#include "head.h"

class Solution {
public:
    map<char, char> nexts;
    map<char, char> pres;
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (nexts.find(s[i]) == nexts.end()) {
                if (pres.find(t[i]) == pres.end()) {
                    nexts[s[i]] = t[i];
                    pres[t[i]] = s[i];
                }
                else
                    return false;
            }
            else {
                if (nexts[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};