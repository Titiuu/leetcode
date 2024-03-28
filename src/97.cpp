#include "head.h"

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), t = s3.size();
        if (m + n != t)
            return false;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i > 0 && dp[i - 1][j] == 1 && s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] = 1;
                }
                if (j > 0 && dp[i][j - 1] == 1 && s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = 1;
                }
            }
        }
        return dp[m][n] == 1;
    }
};

int main() {
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    Solution s;
    cout << s.isInterleave(s1, s2, s3);
}