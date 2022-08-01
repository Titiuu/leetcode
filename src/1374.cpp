#include "head.h"

class Solution {
public:
    string generateTheString(int n) {
        string ret;
        if (n & 1) {
            for (int i = 0; i < n; i++) {
                ret.push_back('a');
            }
        }
        else {
            for (int i = 0; i < n - 1; i++) {
                ret.push_back('a');
            }
            ret.push_back('b');
        }
        return ret;
    }
};