#include "head.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> a(20001, 0);
        for (auto& x : nums) {
            a[x+10000]++;
        }
        int res = 0, count = 0;
        for (int i = 20000; i >= 0; i--) {
            if (a[i] > 0) {
                count += a[i];
                if (count >= k)
                    return i - 10000;
            }
        }
        return 0;
    }
};