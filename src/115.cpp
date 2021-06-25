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

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int slen = s.size(), tlen = t.size();
        if (slen < tlen)    return 0;
        vector<vector<long>> dp(slen + 1,vector<long>(tlen + 1));
        for (int i = 0; i < slen + 1; i++)
            dp[i][0] = 1;
        for (int i = 1; i < tlen + 1; i++)
            dp[0][i] = 0;
        for (int i = 1; i <= slen; i++)
            for (int j = 1; j <= min(i, tlen); j++) {
                if (s[i-1] != t[j-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        return dp[slen][tlen];
    }
};

int main() {
    string s = "babgbag", t = "bag";
    Solution S;
    cout << S.numDistinct(s, t);
}