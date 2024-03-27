#include "head.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 1)
            return triangle[0][0];
        vector<int> temp = { triangle[0][0] };
        for (int i = 1; i < triangle.size(); i++) {
            int n = triangle[i].size();
            vector<int> dp(n, 0);
            dp[0] = temp[0] + triangle[i][0];
            dp[n - 1] = temp[n - 2] + triangle[i][n - 1];
            for (int j = 1; j < n - 1; j++) {
                dp[j] = min(temp[j], temp[j - 1]) + triangle[i][j];
            }
            temp = dp;
        }
        return *min_element(temp.begin(), temp.end());
    }
};