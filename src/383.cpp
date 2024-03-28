#include "head.h"

class Solution {
public:
    unordered_map<char, int> r, m;
    bool canConstruct(string ransomNote, string magazine) {
        for (auto& x : ransomNote) {
            if (r.count(x) == 0)
                r[x] = 1;
            else
                r[x]++;
        }
        for (auto& x : magazine) {
            if (m.count(x) == 0)
                m[x] = 1;
            else
                m[x]++;
        }
        for (auto& x : r) {
            if (m.count(x.first) == 0 || m[x.first] < r[x.first])
                return false;
        }
        return true;
    }
};