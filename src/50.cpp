#include "head.h"

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long N = abs((long long)n);
        bool neg = n > 0 ? false : true;

        while (N > 0) {
            if (N & 1)
                ans *= x;
            N >>= 1;
            x *= x;
        }
        return neg ? 1.0 / ans : ans;
    }
};