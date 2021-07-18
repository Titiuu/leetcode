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
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        for (int i : nums) {
            counts[i]++;
        }
        vector<int> res(2);
        for (int i = 0; i < n; i++) {
            if (counts[i] == 2)
                res[0] = i;
            else if (counts[i] == 0)
                res[1] = i;
        }
        return res;
    }
};