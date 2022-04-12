#include "head.h"

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int rows = 1;
        int pwidth = 0;
        for (auto c : s) {
            if (pwidth + widths[c - 'a'] > 100) {
                rows++;
                pwidth = 0;
            }
            pwidth += widths[c - 'a'];
        }
        return { rows,pwidth };
    }
};