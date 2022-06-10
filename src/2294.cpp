#include "head.h"

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = nums[0], right = nums[0], res = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - left > k) {
                res++;
                left = nums[i];
                right = nums[i];
            }
            else
                right = nums[i];
        }
        return res;
    }
};