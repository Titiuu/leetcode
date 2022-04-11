#include "head.h"

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        if (n == 2) return 91;
        auto arrange = [](int n, int m) {
            int res = 1;
            for (int i = 0; i < m; i++) {
                res *= n;
                n--;
            }
            return res;
        };
        int dp = 91;
        for (int i = 3; i <= n; i++) {
            dp = arrange(10, i) - arrange(9, i - 1) + dp;
        }
        return dp;
    }
};

