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
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> temp(n + 1);
        temp[0] = 0;
        temp[1] = arr[0];
        for (int i = 2; i < n + 1; i++) {
            temp[i] = temp[i-1] ^ arr[i-1];
        }
        int len = queries.size();
        vector<int> res(len);
        for (int i = 0; i < len; i++) {
            res[i] = temp[queries[i][0]] ^ temp[queries[i][1] + 1];
        }
        return res;
    }
};