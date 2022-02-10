#include "head.h"

class Solution { //TLE
public:
    int maxSubArray(vector<int>& nums) {
        int res = -10000;
        for (size_t i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (size_t j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum > res)
                    res = sum; 
            }
        }
        return res;
    }
};

class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (auto x : nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};