#include "head.h"

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int res = INT32_MIN;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += i * nums[i];
        }
        res = max(ans, res);
        for (int i = 1; i < n; i++) {
            ans = ans + sum - n * nums[n - i];
            res = max(ans, res);
        }
        return res;
    }
};