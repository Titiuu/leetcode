#include "head.h"

class Solution {
private:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (auto x : nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
    int minSubArray(vector<int>& nums) {
        int pre = 0, minAns = nums[0];
        for (auto x : nums) {
            pre = min(pre + x, x);
            minAns = min(minAns, pre);
        }
        return minAns;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int ans = maxSubArray(nums), sum = accumulate(nums.begin(), nums.end(), 0);
        int ans1 = sum - minSubArray(nums);
        if (ans1 == 0)
            return ans;
        ans = max(ans, ans1);
        return ans;
    }
};