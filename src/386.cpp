#include "head.h"

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int num = 1;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            res.emplace_back(num);
            if (num * 10 <= n)
                num *= 10;
            else {
                while ((num % 10 == 9) || num == n) {
                    num = num / 10;
                }
                num++;
            }
        }
        return res;
    }
};