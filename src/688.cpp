#include "head.h"

class Solution {
public:
    vector<vector<int>> dirs = {{2, -1}, {2, 1}, {1, -2}, {1, 2}, {-1, -2}, {-1, 2}, {-2, -1}, {-2, 1}};
    double dp[26][26][101];
    int n_size;
    
    double dfs(int x, int y, int k) {
        if (x < 0 || x >= n_size || y < 0 || y >= n_size)
            return 0;
        if (k == 0)
            return 1;
        if (dp[x][y][k] != 0)
            return dp[x][y][k];
        for (int i = 0; i < 8; i++) 
            dp[x][y][k] += 1.0 / 8 * dfs(x + dirs[i][0], y + dirs[i][1], k - 1);
        return dp[x][y][k];
    }

    double knightProbability(int n, int k, int row, int column) {
        n_size = n;
        return dfs(row, column, k);
    }
};