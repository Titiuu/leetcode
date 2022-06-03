#include "head.h"

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0; n *= 2;
        for (int k = 1; k * k < n; k++) {
            if (n % k == 0)
                if ((n / k - (k - 1)) % 2 == 0)
                    ans++;
        }
        return ans;
    }
};