#include "head.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 1; // 至少为1
        vector<int> dp(n, 1); //dp[i+1] = dp[i] + 1 if(nums[i+1]>nums[i]) else dp[i+1] = 1 (do nothing)
        for (int i = 1; i < n; i++) {
            int len = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] <= nums[j] + k && nums[i] > nums[j])
                    len = max(len, dp[j] + 1);
            }
            dp[i] = len;
            res = max(res, len);
        }
        return res;
    }
};

class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        vector<int> p { nums[0] };
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > p.back() && nums[i] <= p.back() + k)
                p.emplace_back(nums[i]);
            else if(nums[i] < p.back()){
                auto j = lower_bound(p.begin(), p.end(), nums[i]);
                *j = nums[i];
            }
        }
        return p.size();
    }
};

int main() {
    Solution1 s;
    vector<int> nums { 1,3,3,4 };
    s.lengthOfLIS(nums, 1);
}