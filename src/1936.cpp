#include "head.h"

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int pre = 0;
        int res = 0;
        for (auto& r : rungs) {
            res += (int)ceil((double(r) - double(pre)) / dist) - 1;
            pre = r;
        }
        return res;
    }
};