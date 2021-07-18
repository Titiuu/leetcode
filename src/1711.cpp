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
    static constexpr int MOD = 1'000'000'007;

    int countPairs(vector<int>& deliciousness) {
        int maxVal = *max_element(deliciousness.begin(), deliciousness.end());
        int maxSum = maxVal * 2;
        int pairs = 0;
        unordered_map<int, int> mp;
        int n = deliciousness.size();
        for (auto& val : deliciousness) {
            for (int sum = 1; sum <= maxSum; sum <<= 1) {
                int count = mp.count(sum - val) ? mp[sum - val] : 0;
                pairs = (pairs + count) % MOD;
            }
            mp[val]++;
        }
        return pairs;
    }
};