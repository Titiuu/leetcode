#include "head.h"

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(), ans = values[0] + values[1] - 1;
        if (n == 2)
            return ans;
        int maxAns = ans;
        for (int i = 2; i < n; i++) {
            ans = max(ans - values[i - 1] + values[i] - 1, values[i - 1] + values[i] - 1);
            maxAns = max(ans, maxAns);
        }
        return maxAns;
    }
};