#include "head.h"

class Solution {
public:
    bool isValid(string s) {
        while (!s.empty()) {
            string temp;
            for (int i = 0;i < s.size();i++) {
                if (s[i] == 'a') {
                    i++;
                    if (s[i] == 'b') {
                        i++;
                        if (s[i] == 'c') {
                            continue;
                        }
                        else i-=2;
                    }
                    else i--;
                }
                temp.push_back(s[i]);
            }
            if (temp == s)
                return false;
            s = temp;
        }
        return true;
    }
};