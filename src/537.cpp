#include "head.h"

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        regex re("\\+|i"); 
        vector<string> complex1(sregex_token_iterator(num1.begin(), num1.end(), re, -1), std::sregex_token_iterator());
        vector<string> complex2(sregex_token_iterator(num2.begin(), num2.end(), re, -1), std::sregex_token_iterator());
        int real1 = stoi(complex1[0]);
        int imag1 = stoi(complex1[1]);
        int real2 = stoi(complex2[0]);
        int imag2 = stoi(complex2[1]);
        return to_string(real1 * real2 - imag1 * imag2) + "+" + to_string(real1 * imag2 + imag1 * real2) + "i";
    }
};
