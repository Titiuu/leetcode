#include "head.h"

class Solution {
public:
    vector<string> ans;
    void backtrace(string& s, int cnt, int index, string& str) {
        if (cnt == 4 || index == s.size()) {
            if (cnt == 4 && index == s.size())
                ans.push_back(str.substr(0, str.size() - 1));
            return;
        }
        for (int i = 1; i <= 3; i++) {
            if (index + i > s.size()) return;
            if (s[index] == '0' && i != 1) return;
            if (i == 3 && s.substr(index, i) > "255") return;
            str += s.substr(index, i);
            str.push_back('.');
            backtrace(s, cnt + 1, index + i, str);
            str = str.substr(0, str.size() - i - 1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string str = "";
        backtrace(s, 0, 0, str);
        return ans;

    }
};