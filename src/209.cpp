#include "head.h"

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 1, sum = nums[0], res = 1e8;
        while (right <= nums.size() || sum >= target) {
            if (sum >= target) {
                res = min(res, right - left);
                sum -= nums[left];
                left++;
            }
            else {
                sum += nums[right];
                right++;
            }
        }
        return res == 1e8 ? 0 : res;
    }
};