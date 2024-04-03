#include "head.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        bool flag = (target < nums[0] ? true : false);
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;            
            else if (flag && nums[mid] >= nums[0]) { // 收缩左边界
                left = mid + 1;
            }
            else if (!flag && nums[mid] <= nums[0]) { // 收缩右边界
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums { 3,1 };
    Solution s;
    cout << s.search(nums, 1);
}