#include "head.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        nums.insert(nums.begin(),nums.end()-k,nums.end());
        nums.resize(n);
    }
};

class Solution1 {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }

    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};

int main() {
    Solution s;
    vector<int> nums = { 1,2,3 };
    s.rotate(nums, 1);
    for (auto x : nums)
        cout << x;
}