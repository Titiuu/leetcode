#include "head.h"

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a1 = edges[0][0], a2 = edges[0][1], a3 = edges[1][0], a4 = edges[1][1];
        if (a1 == a3 || a1 == a4)   return a1;
        return a2;
    }
};