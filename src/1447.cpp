#include "head.h"

class Solution {
public:
    int gcd(int x, int y) {
        int z = y;
        while (x % y != 0) {
            z = x % y;
            x = y;
            y = z;
        }
        return z;
    }

    vector<string> simplifiedFractions(int n) {
        int i = 2, j = 1;
        vector<string> res;
        for (; i <= n; i++) {
            for ( j = 1; j < i; j++) {
                if (gcd(i, j) == 1)
                    res.push_back(to_string(j) + "/" + to_string(i));
            }
        }
        return res;
    }
};