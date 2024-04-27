#include "head.h"

class Solution1 { // 错误在于 如果当前字符串是合理的，它不一定由长度比它小2的字符串转移过来
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int res = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // 初始化长度为2的括号，长度为1一定false
        for (int i = 0; i < n-1; i++){
            if(s[i] == '(' && s[i+1] == ')'){
                dp[i][i+1] = true;
                res = 2;
            }
        }
        for (int j = 3; j < n; j += 2){ 
            for (int i = 0; i + j < n; i++){
                if(dp[i][i+j-2]){
                    if(s[i+j-1] == '(' && s[i+j] == ')'){
                        dp[i][i+j] = true;
                        res = max(res, j+1);
                    }
                }
                if(dp[i+2][i+j]){
                    if(s[i] == '(' && s[i+1] == ')'){
                        dp[i][i+j] = true;
                        res = max(res, j+1);
                    }
                }
                if(dp[i+1][i+j-1]){
                    if(s[i] == '(' && s[i+j] == ')'){
                        dp[i][i+j] = true;
                        res = max(res, j+1);
                    }
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int res = 0;
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(')
                    dp[i] = i - 2 >= 0 ? dp[i - 2] + 2 : 2;
                else {
                    if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
                        dp[i] = i - dp[i - 1] - 2 >= 0 ? dp[i - 1] + dp[i - dp[i - 1] - 2] + 2 : dp[i - 1] + 2;
                }
            }
            res = max(res, dp[i]);
        }
        
        return res;
    }
};

int main() {
    Solution s;
    cout << s.longestValidParentheses(")(((((()())()()))()(()))(");
}