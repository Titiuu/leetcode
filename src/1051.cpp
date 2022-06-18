#include "head.h"

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> copy = heights;
        sort(heights.begin(), heights.end());
        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != copy[i])
                res++;
        }
        return res;
    }
};