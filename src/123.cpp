#include "head.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = -1e8, buy2 = -1e8;
        int sell1 = 0, sell2 = 0;
        for (auto& p : prices) {
            int new_buy1 = max(buy1, -p);
            int new_sell1 = max(sell1, p + buy1);
            int new_buy2 = max(buy2, sell1 - p);
            int new_sell2 = max(sell2, buy2 + p);
            buy1 = new_buy1;
            buy2 = new_buy2;
            sell1 = new_sell1;
            sell2 = new_sell2;
        }
        return sell2;
    }
};