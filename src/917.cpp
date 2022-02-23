#include "head.h"

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        vector<char> temp;
        for (int i = 0; i < n; i++) {
            if (isalpha(s[i]))
                temp.push_back(s[i]);
        }
        int index = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (isalpha(s[i])) {
                s[i] = temp[index];
                index++;
            }
        }
        return s;
    }
};