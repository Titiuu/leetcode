#include "head.h"

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numSet;
        for (auto x : nums) {
            if (numSet.count(x) != 0)
                return true;
            numSet.insert(x);
        }
        return false;
    }
};