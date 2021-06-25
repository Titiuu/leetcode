#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

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

int main(){
    Solution1 test;
    vector<int> a={1,2,3,4};
    cout<<test.twoSum(a,6)[0]<<","<<test.twoSum(a,6)[1];
}