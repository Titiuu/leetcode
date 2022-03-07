#include "head.h"

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j;
        for (i = 0; i < (int)nums.size(); i++)
            for (j = i + 1; j < (int)nums.size(); j++)
                if (nums[i] + nums[j] == target) goto sss;
        sss:
        vector<int> a={i,j};
        return a;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

int main(){
    Solution1 test;
    vector<int> a={1,2,3,4};
    cout<<test.twoSum(a,6)[0]<<","<<test.twoSum(a,6)[1];
}