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
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector<int> res(n+1);
        res[0] = first;
        for (int i = 1; i < n + 1; i++)
        {
            res[i] = res[i-1] ^ encoded[i-1];
        }
        return res; 
    }
};