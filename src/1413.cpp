#include "head.h"

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int mn = 0, start = 0;
        for (int i = 0; i < nums.size(); i++) {
            start += nums[i];
            mn = min(mn, start);
        }
        return 1 - mn;
    }
};