#include "head.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxTimes = 0, preKey = nums[0];
        for (auto& x : nums) {
            if (mp.find(x) != mp.end()) {
                mp[x]++;
                if (mp[x] > maxTimes) {
                    maxTimes = mp[x];
                    preKey = x;
                }
            }
            else
                mp[x] = 1;
        }
        return preKey;
    }
};