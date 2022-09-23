#include "head.h"

class Solution {
public:
    bool halvesAreAlike(string s) {
        string set = "AEIOUaeiou";
        int n = s.size();
        int count = 0;
        for (int i = 0; i < (n + 1) / 2; i++) {
            if (set.find(s[i]) != s.npos) {
                count++;
            }
        }
        for (int i = (n + 1) / 2; i < n; i++) {
            if (set.find(s[i]) != s.npos) {
                count--;
            }
        }
        return count == 0;
    }
};