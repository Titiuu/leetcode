#include "head.h"

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int len = nums.size();
//         if (len < 3)
//             return max(nums[0], nums[1]);
//         vector<int> dp(len + 1, 0);
//         int count = 0;
//         if (nums[0] > nums[1]) {
//             dp[0] = 1;
//             count = dp[0];
//         }
//         else {
//             dp[1] = 1;
//             count = dp[1];
//         }
//         for (size_t i = 2; i < len; i++) {
//             if (dp[i-1] == 0) {
//                 dp[i] = 1;
//                 count += nums[i];
//             }
//             else {
//                 if (nums[i] > count) {
//                     count = nums[i];
//                     dp[i] = 1;
//                     dp[i-1] = 0;
//                 }   
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 1)   return nums[0];
        if (len < 3)
            return max(nums[0], nums[1]);
        vector<int> dp(len + 1, 0);
        dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
        for (size_t i = 2; i < len; i++) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[len - 1];
    }
};