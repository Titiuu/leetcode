#include "head.h"

class Solution {
public:
    int numTrees(int n) {
        vector<long long> dp(n + 1);  //直接做乘法可能越界
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            dp[i] = dp[i - 1] * (4 * i - 2) / (i + 1);
            //dp[i] = (4 * i - 2) / (i + 1) * dp[i - 1];  //出错，因为非整除
        }
        return (int)dp[n];
    }
};