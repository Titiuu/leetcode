#include "head.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> temp(n, 0);
        temp[0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            temp[i] = temp[i - 1] + grid[0][i];
        }
        if (m == 1)
            return temp[n - 1];
        for (int i = 1; i < m; i++) {
            vector<int> dp(n, 0);
            dp[0] = temp[0] + grid[i][0];
            for (int j = 1; j < n; j++) {
                dp[j] = min(dp[j - 1], temp[j]) + grid[i][j];
            }
            temp = dp;
        }
        return temp[n - 1];
    }
};