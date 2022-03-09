#include "head.h"

class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size(), val = 0;
        for (int i = 0; i < n; i++)
            if (nums[i] <= i)
                val++;  //算初始值
        vector<int> steps(n, 0);    //每个k对应多少下标相等的
        for (int i = 0; i < n; i++) {
            if (nums[i] <= i)
                steps[i - nums[i]]++;
            else
                steps[i + n - nums[i]]++;
        }
        int ans = 0, maxval = val;
        for (int i = 1; i < n; i++) {
            //状态转移，多移一位，上次的分数要减去上次刚好值与下标相等的元素（多移一位就丧失分数）
            //首位移动到末位必多一分
            val = val - steps[i - 1] + 1;
            if (val > maxval) {
                ans = i;
                maxval = val;
            }
        }
        return ans;
    }
};