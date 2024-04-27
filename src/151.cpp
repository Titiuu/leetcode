#include "head.h"

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                string temp = "";
                while (i >= 0 && s[i] != ' ') {
                    temp.insert(temp.begin(), s[i]);
                    i--;
                }
                ans += temp + ' ';
            }
        }
        ans.pop_back();
        return ans;
    }
};