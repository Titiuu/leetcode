#include "head.h"

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        int m = accounts.size(), n = accounts[0].size();
        for (auto savings : accounts) {
            int count = 0;
            for (auto x : savings) {
                count += x;
            }
            res = max(count, res);
        }
        return res;
    }
};