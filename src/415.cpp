#include "head.h"

class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        string res;
        int carry = 0;
        int i = n1 - 1, j = n2 - 1;
        while(i>=0 && j>=0){
            int c = num1[i] - '0' + num2[j] - '0' + carry;
            if (c > 9){
                c -= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            res.insert(res.begin(), (char)(c + '0'));
            i--;
            j--;
        }
        while (i >= 0) {
            int c = num1[i] - '0' + carry;
            if (c > 9){
                c -= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            res.insert(res.begin(), (char)(c + '0'));
            i--;
        }
        while (j >= 0) {
            int c = num1[j] - '0' + carry;
            if (c > 9){
                c -= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            res.insert(res.begin(), (char)(c + '0'));
            j--;
        }
        return res;
    }
};