#include "head.h"

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> buy(k, -1e8), sell(k, 0);
        for (auto& p : prices) {
            buy[0] = max(buy[0], -p);
            sell[0] = max(sell[k], p + buy[0]);
            for (int i = 1; i < k; i++) {
                buy[i] = max(buy[i], sell[i-1]-p);
                sell[i] = max(sell[i], p + buy[i]);
            }
        }
        return sell[k - 1];
    }
};