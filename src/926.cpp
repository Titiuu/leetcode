#include "head.h"

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> zeros(n + 1);
        vector<int> ones(n + 1);
        for (int i = 1, count = 0; i < n + 1; i++) {
            if (s[i - 1] == '1')
                count++;
            zeros[i] = count;
        }
        for (int i = n, count = 0; i > 0; i--) {
            if (s[i - 1] == '0')
                count++;
            ones[i - 1] = count;
        }
        int res = 99999;
        for (int i = 0; i < n + 1; i++) {
            res = min(res, zeros[i] + ones[i]);
        }
        return res;
    }
};