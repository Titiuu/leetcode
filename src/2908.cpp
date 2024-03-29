#include "head.h"

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 51), right(n, 51);
        for (int i = 1; i < n; i++) {
            left[i] = min(nums[i - 1], left[i - 1]);
        }
        for (int i = n-2; i >= 0; i--) {
            right[i] = min(nums[i + 1], right[i + 1]);
        }
        int ans = 1e8;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > left[i] && nums[i] > right[i])
                ans = min(ans, nums[i] + left[i] + right[i]);
        }
        return ans == 1e8 ? -1 : ans;
    }
};