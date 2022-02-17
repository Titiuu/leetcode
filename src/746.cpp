#include "head.h"

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(1002, 0);
        for (size_t i = 2; i <= cost.size(); i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[cost.size()];
    }
};