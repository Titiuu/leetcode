#include "head.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1);
        int a = 1, b = 1;
        for (int i = 0, j = n - 1; i < n - 1; i++, j--) {
            a *= nums[i];
            left[i + 1] = a;
            b *= nums[j];
            right[j + 1] = b;
        }
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            ans[i] = left[i] * right[n - i - 1];
        }
        return ans;
    }
};