#include "head.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3));
        dp[0][0] = -prices[0], dp[0][1] = 0, dp[0][2] = 0;
        for (int i = 1; i < n; i++) { // 0是持有，1是未持有处于冷冻期，2是未持有未处于冷冻期
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
        }
        return max(dp[n - 1][1], dp[n - 1][2]);
    }
};