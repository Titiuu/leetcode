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

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<bool> g(n, false);

        for (int i = 0; i < n - 1; ++i) {
            int num = atoi(s.substr(i, 2).c_str());
            g[i] = (num > 0 && num < 27) && s[i] != '0';
        }
        vector<int> f(n + 1, 0);
        f[0] = 1;
        f[1] = 1;
        for (int i = 2; i < n + 1; ++i)
        {
            if (s[i-1] != '0') {
                if (g[i - 2])
                    f[i] = f[i - 2] + f[i - 1];
                else
                    f[i] = f[i - 1];
            }
            else {
                if (g[i - 2])
                    f[i] = f[i - 2];
                else
                    return 0;
            }
        }
        return f[n];
    }
};

int main() {
    Solution S;
    cout<<S.numDecodings("01");
    return 0;
}