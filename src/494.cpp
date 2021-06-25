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
int tar;
vector<int> n;
int count;

void backtrack(int t, int len, int sum) {
    //终止条件(递归必须要有终止条件)
    if (t==len) {
        if (sum == tar)
            count++;
        return;
    }
    backtrack(t + 1, len, sum + n[t]);
    backtrack(t + 1, len, sum - n[t]);
}
    int findTargetSumWays(vector<int>& nums, int target) {
        tar = target;
        n = nums;
        count = 0;
        backtrack(0, nums.size(), 0);
        return count;
    }
};

class Solution1 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int& num : nums) {
            sum += num;
        }
        int diff = sum - target;
        if (diff < 0 || diff % 2 != 0) {
            return 0;
        }
        int n = nums.size(), neg = diff / 2;
        vector<vector<int>> dp(n + 1, vector<int>(neg + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int num = nums[i - 1];
            for (int j = 0; j <= neg; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= num) {
                    dp[i][j] += dp[i - 1][j - num];
                }
            }
        }
        return dp[n][neg];
    }
};