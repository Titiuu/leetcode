#include "head.h"

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans(n, 10000);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c) {
                ans[i] = 0;
                int p, q;
                for (p = i - 1; p >= 0; p--) {
                    if (s[p] != c) {
                        ans[p] = min(ans[p], i - p);
                    }
                    else
                        break;
                }
                for (q = i + 1; q < n; q++) {
                    if (s[q] != c) {
                        ans[q] = min(ans[q], q - i);
                    }
                    else {
                        i = q - 1;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};