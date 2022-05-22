#include "head.h"

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> left(n);
        for (int i = 0; i < n; i++) {
            left[i] = capacity[i] - rocks[i];
        }
        sort(left.begin(), left.end());
        int res = 0;
        for (auto& x : left) {
            if (x == 0)
                res++;
            else {
                if (additionalRocks >= x) {
                    additionalRocks -= x;
                    res++;
                }
                else
                    break;
            }
        }
        return res;
    }
};