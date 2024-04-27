#include "head.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ans(num1.size() + num2.size(), '0');
        int carry = 0;
        for (int i = 0; i < num1.size(); ++i) {
            for (int j = 0; j < num2.size(); ++j) {
                carry += (num1[i] - '0') * (num2[j] - '0') + (ans[i + j] - '0');
                ans[i + j] = '0' + carry % 10;
                carry /= 10;
            }
            if (carry > 0) {
                ans[i + num2.size()] = ('0' + carry);
                carry = 0;
            }
        }
        if (ans.back() == '0') {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};