#include "head.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        auto dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 1e8));
        dp[0][0] = 0;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i > 0)
                    dp[i][j] = dp[i - 1][j] + 1;
                if (j > 0)
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                if (i > 0 && j > 0)
                    if (word1[i - 1] != word2[j - 1])
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                    else
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
        }
        return dp[m][n];
    }
};