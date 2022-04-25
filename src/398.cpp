#include "head.h"

class Solution {
    vector<int> &nums;
public:
    Solution(vector<int> &nums) : nums(nums) {}

    int pick(int target) {
        int ans;
        for (int i = 0, cnt = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                ++cnt; // 第 cnt 次遇到 target
                if (rand() % cnt == 0) {
                    ans = i;
                }
            }
        }
        return ans;
    }
};