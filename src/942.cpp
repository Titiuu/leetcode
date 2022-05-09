#include "head.h"

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> res(n + 1);
        for (int i = 0; i < n + 1; i++) {
            res[i] = i;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == 'D') {
                int start = i;
                while (i < n && s[i] == 'D')
                    i++;
                //转置
                reverse(res.begin() + start, res.begin() + i + 1);
            }
        }
        return res;
    }
};