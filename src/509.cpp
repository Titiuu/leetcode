#include "head.h"

class Solution {
public:
    int fib(int n) {
        vector<int> dp(31, 0);
        dp[0] = 0, dp[1] = 1;
        for (size_t i = 2; i < 31; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};