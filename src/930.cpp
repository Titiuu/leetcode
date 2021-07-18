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
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int len = nums.size();
        vector<int> presums(len + 1, 0);
        int sum = 0;
        for (int i = 0; i < len; i++) {
            presums[i] = sum;
            sum += nums[i];
        }
        presums[len] = sum;
        int res = 0;
        for (int i = 0; i < len + 1 - goal; i++) {
            for (int j = i + 1; j < len + 1; j++) {
                if (presums[j] - presums[i] == goal)
                    res++;
                else if (presums[j] - presums[i] > goal)
                    break;
            }
        }
        return res;
    }
};