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
        int ret = 0;

        if (goal == 0) {
            int count = 0;
            for (int i : nums) {
                if (i == 0) {
                    count++;
                }
                else {
                    ret += count * (count + 1) / 2;
                    count = 0;
                }
            }
            ret += count * (count + 1) / 2;
            return ret;
        }

        vector<int> presums(len + 1, 0);
        int sum = 0;
        for (int i = 0; i < len; i++) {
            presums[i] = sum;
            sum += nums[i];
        }
        presums[len] = sum;
        if (sum < goal) return 0;

        for (int i = 0; i < len + 1 - goal; i++) {
            int res = 0;
            int index = i + goal;
            for (int j = i + goal; j < len + 1; j++) {
                if (presums[j] - presums[i] == goal)
                    res++;
                else if (presums[j] - presums[i] > goal)
                {
                    index = j;
                    break;
                }
            }
            ret += res;
            while (i < index && nums[i] == 0) {
                ret += res;
                i++;
            }
        }
        return ret;
    }
};