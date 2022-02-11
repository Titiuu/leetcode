#include "head.h"

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 100000;
        for (size_t i = 0; i < nums.size() - k + 1; i++)
        {
            int temp = nums[i + k - 1] - nums[i];
            if (temp < res) {
                if (temp == 0)  return 0;
                res = temp;
            }
        }
        return res;
    }
};