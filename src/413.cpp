#include "head.h"

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return 0;
        int res = 0, pre = 0;
        if (nums[1] - nums[0] == nums[2] - nums[1]) {
            pre = 1;
            res++;
        }
        for (int i = 3; i < n; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                pre++;
                res += pre;
            }
            else
                pre = 0;
        }
        return res;
    }
};