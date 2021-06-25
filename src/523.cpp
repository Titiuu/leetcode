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

class Solution { //TLE
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            int res = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                res += nums[j];
                if (res % k == 0)   return true;
            }
        }
        return false;
    }
};

class Solution1 {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pres(n+1);
        int count = 0;
        for (int i = 0; i < n; i++) {
            pres[i] = count;
            count = (count + nums[i] % k) % k;
        }
        pres[n] = count;
        unordered_map<int, int> map;
        for (int i = 1; i < n + 1; i++) {
            if (pres[i] == 0 && i != 1) return true;
            if (map.find(pres[i]) == map.end())
                map[pres[i]] = i;
            else if (i - map[pres[i]] > 1)
                return true;
        }
        return false;
    }
};