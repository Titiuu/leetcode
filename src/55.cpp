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

class Solution1 {
public:
    bool canJump(vector<int>& nums) {
        int maxDis = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i <= maxDis) {
                maxDis = max(maxDis, i + nums[i]);
            }
        }
        return maxDis >= nums.size() - 1;
    }
};