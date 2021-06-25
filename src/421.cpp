#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <regex>
#include <cmath>
#include <numeric>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((long long)(nums[i]) + nums[j] < res)
                    break;
                res = max(res, nums[i] ^ nums[j]);
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> nums = {3,10,5,25,2,8};
    cout<<S.findMaximumXOR(nums);
}