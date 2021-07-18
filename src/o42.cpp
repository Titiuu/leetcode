#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <regex>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (auto x: nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};