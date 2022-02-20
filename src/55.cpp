#include "head.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int canReach = 0;
        for (int i = 0; i < n; i++) {
            if (i <= canReach) {
                canReach = max(i + nums[i], canReach);
            }
            else
                break;
        }
        return canReach >= n - 1;
    }
};