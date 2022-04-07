#include "head.h"

class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.size(), n = goal.size();
        if (m != n)
            return false;
        for (int i = 0; i < m; i++) {
            string t1(s, i, m - i);
            string t2(s, 0, i);
            if (t1 + t2 == goal)
                return true;
        }
        return false;
    }
};

class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
};