#include "head.h"

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int ret = 0;
        int pp = 1, i = 0;
        for (int j = 0; j < n; j++) {
            pp *= nums[j];
            while (i <= j && pp >= k) {
                pp /= nums[i];
                i++;
            }
            ret += j - i + 1;
        }
        return ret;
    }
};