#include "head.h"

class Solution {
public:
    bool oneEditAway(string first, string second) {
        if (first == second)
            return true;
        int m = first.size(), n = second.size();
        if (abs(m - n) > 1)
            return false;
        else {
            int front = 0, back = 0;
            for (int i = 0; i < min(m, n); i++) {
                if (first[i] == second[i])
                    front++;
                else
                    break;
            }
            for (int j = m - 1, k = n - 1; j >= 0 && k >= 0; j--, k--) {
                if (first[j] == second[k])
                    back++;
                else
                    break;
            }
            int l = m == n ? m - 1 : min(m, n);
            if (front + back == l)
                return true;
        }
        return false;
    }
};