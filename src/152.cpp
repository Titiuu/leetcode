#include "head.h"

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int maxF = 1, minF = 1, ans = nums[0];
        for (auto &x : nums) {
            int maxT = maxF, minT = minF;
            maxF = max(maxT * x, max(x, minT * x));
            minF = min(minT * x, min(x, maxT * x));
            ans = max(maxF, ans);
        }
        return ans;
    }
};
