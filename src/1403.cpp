#include "head.h"

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return a > b;
            });
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int acc = 0;
        vector<int> ret;
        for (auto& x : nums) {
            acc += x;
            ret.push_back(x);
            if (acc > sum / 2)
                break;
        }
        return ret;
    }
};