#include "head.h"

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i <= j) {
            if (!isalnum(s[i]))
                i++;
            if (!isalnum(s[j]))
                j--;
            if (isalnum(s[i]) && isalnum(s[j])) {
                if (s[i] == s[j] || (isalpha(s[i]) && isalpha(s[j]) && abs(s[i] - s[j]) == 32)) {
                    i++;
                    j--;
                }
                else
                    return false;
            }
        }
        return true;
    }
};