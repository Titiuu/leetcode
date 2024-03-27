#include "head.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int res = 1; // 至少为1
        vector<int> dp(n, 1); //dp[i+1] = dp[j] + 1 if(nums[i+1]>nums[j]) else dp[i+1] = 1 (do nothing)
        for (int i = 1; i < n; i++) {
            int len = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j])
                    len = max(len, dp[j] + 1);
            }
            dp[i] = len;
            res = max(res, len);
        }
        return res;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> p { nums[0] };
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > p.back())
                p.emplace_back(nums[i]);
            else {
                auto j = lower_bound(p.begin(), p.end(), nums[i]);
                *j = nums[i];
            }
        }
        return p.size();
    }
};