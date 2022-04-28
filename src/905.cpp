#include "head.h"

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        deque<int> res;
        for (auto x : nums) {
            if (x & 1)
                res.emplace_back(x);
            else
                res.emplace_front(x);
        }
        vector<int> ans(res.begin(), res.end());
        return ans;
    }
};