#include "head.h"

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> jumpsNeed(n, 9999);
        jumpsNeed[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j < n) 
                    jumpsNeed[i + j] = min(jumpsNeed[i] + 1, jumpsNeed[i + j]);
            }
        }
        return jumpsNeed[n - 1];
    }
};

class Solution1 {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 1e9);
        dp[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j < nums.size())
                    dp[i + j] = min(dp[i] + 1, dp[i + j]);
            }
        }
        return dp[nums.size() - 1];
    }
};