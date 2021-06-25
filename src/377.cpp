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
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int num = 1; num <= target; num++) {
            for(auto &ele : nums) {
                if(ele > num) break;
                dp[num] = 0LL + dp[num] + dp[num-ele] % INT_MAX;
            }
        }
        return dp[target];
    }
};