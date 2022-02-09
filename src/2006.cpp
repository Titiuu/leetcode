#include "head.h"

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int i, j, count = 0;
        for (i = 0; i < nums.size() - 1; i++) {
            for (j = i + 1; j < nums.size(); j++) {
                if (abs(nums[i] - nums[j]) == k)
                    count++;
            }
        }
        return count;
    }
};

class Solution1 {
public:
    int countKDifference(vector<int>& nums, int k) {
        vector<int> cnts(101, 0);
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int t = nums[i];
            if (t - k >= 1) ans += cnts[t - k];
            if (t + k <= 100) ans += cnts[t + k];
            cnts[t]++;
        }
        return ans;
    }
};