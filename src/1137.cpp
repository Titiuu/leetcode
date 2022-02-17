#include "head.h"

class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(38, 0);
        dp[0] = 0, dp[1] = 1, dp[2] = 1;
        for (size_t i = 3; i < n + 1; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }
};