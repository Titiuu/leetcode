#include "head.h"

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size(), n = strs[0].size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            char front = 'a' - 1;
            for (int j = 0; j < m; j++) {
                if (strs[j][i] < front) {
                    res++;
                    break;
                }
                front = strs[j][i];
            }
        }
        return res;
    }
};