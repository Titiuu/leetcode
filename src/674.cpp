#include "head.h"

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        stack<int> stk;
        int res = 0;
        for (auto& x : nums) {
            if (stk.empty() || x > stk.top())
                stk.push(x);
            else {
                stack<int>().swap(stk);
                stk.push(x);
            }
            res = max(res, (int)stk.size());
        }
        return res;
    }
};