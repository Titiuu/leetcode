#include "head.h"

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(46, 1);
        for (size_t i = 2; i < n + 1; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};