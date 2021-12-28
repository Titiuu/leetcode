#include "head.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (target == nums[mid])
                return mid;
            if (target < nums[mid]) {
                if (j == mid) break;
                    j = mid;
            }
            else if (target > nums[mid])
                i = mid + 1;  
        }
        return i;
    }
};

int main() {
    Solution S;
    vector<int> L = {1};
    int target = 0;
    cout << S.searchInsert(L, target);
}