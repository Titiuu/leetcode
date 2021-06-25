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
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> pres(n+1);
        int count = 0;
        for (int i = 0; i < n; i++) {
            pres[i] = count;
            count += nums[i] * 2 - 1;
        }
        pres[n] = count;
        unordered_map<int, int> map;
        int len = 0;
        for (int i = 0; i < n + 1; i++) {
            if (map.find(pres[i]) == map.end())
                map[pres[i]] = i;
            else if (i - map[pres[i]] > len)
                len = i - map[pres[i]];
        }
        return len;
    }
};