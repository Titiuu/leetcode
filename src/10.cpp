#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        //******想要通过删除相邻重复字符的方法进行简化的方法不是那么简单的******
        // string s1=s, p1=p;
        // if(p.find('*') != string::npos && p.find('.') == string::npos)
        // {
        //     s1.clear();
        //     p1.clear();
        //     char temp = '+';
        //     for (auto c : s)
        //     {
        //         if (temp != c)
        //             s1 += c;
        //         temp = c;
        //     }
        //     temp = '+';
        //     for (auto c : p)
        //     {
        //         if (temp != c || c == '.')
        //             p1 += c;
        //         temp = c;
        //     }
        // }
        
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1)) {
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }
};

int main()
{
    Solution S;
    cout << S.isMatch("mississippi","mis*is*p*.");
}