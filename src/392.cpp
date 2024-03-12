#include "head.h"

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (t == "" && s != "")
            return false;
        for (int i = 0, j = 0; i < s.size(); i++, j++) {
            while (t[j] != s[i]) {
                j++;
                if (j == t.size())
                    return false;
            }
            if (j + 1 == t.size()) {
                if (i + 1 == s.size())
                    return true;
                return false;
            }
        }
        return true;
    }
};