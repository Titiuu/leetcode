#include "head.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> temp(n, 0);
        if (grid[0][0] == 1)
            temp[0] = 0;
        else 
            temp[0] = 1;
        for (int i = 1; i < n; i++) {
            if (grid[0][i] == 1)
                temp[i] = 0;
            else
                temp[i] = temp[i - 1];
        }
        if (m == 1)
            return temp[n - 1];
        for (int i = 1; i < m; i++) {
            vector<int> dp(n, 0);
            if (grid[i][0] == 1)
                dp[0] = 0;
            else
                dp[0] = temp[0];
            for (int j = 1; j < n; j++) {
                if (grid[i][j] == 1)
                    dp[j] = 0;
                else
                    dp[j] = dp[j - 1] + temp[j];
            }
            temp = dp;
        }
        return temp[n - 1];
    }
};

int main() {
    vector<vector<int>> grid { {0,0,0},{0,1,0},{0,0,0} };
    Solution s;
    cout << s.uniquePathsWithObstacles(grid);
}