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
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size();
        int xorN;
        switch ((n + 1) % 4) {
            case 1: {
                xorN = 1;
                break;
            } case 2: {
                xorN = n + 2;
                break;
            } case 3: {
                xorN = 0;
                break;
            } default: {
                xorN = n + 1;
                break;
            }
        }

        int exceptFirst = 0;
        for (int i = 1; i < n; i += 2) {
            exceptFirst ^= encoded[i];
        }

        vector<int> ans(n + 1);
        ans[0] = exceptFirst ^ xorN;
        for (int i = 1; i <= n; ++i) {
            ans[i] = ans[i - 1] ^ encoded[i - 1];
        }
        return ans;
    }
};