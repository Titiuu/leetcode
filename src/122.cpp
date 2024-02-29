#include "head.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {   
        int ans = 0;
        int n = prices.size();
        for (int i = 1; i < n; ++i) {
            ans += prices[i] - prices[i - 1] > 0 ? prices[i] - prices[i - 1] : 0;
        }
        return ans;
    }
};

class Solution1 {
private:
    stack<int> stk;
public:
    int maxProfit(vector<int>& prices) {
        int bottom = prices[0], ans = 0;
        stk.push(prices[0]);
        for (auto& x : prices) {
            if (stk.top() <= x) {
                stk.push(x);
            }
            else {
                ans = ans + stk.top() - bottom;
                bottom = x;
                stk = stack<int>({ x });
            }
        }
        return ans + stk.top() - bottom;
    }
};

int main() {
    Solution1 s;
    vector<int> prices = {7,1,5,3,6,4};
    cout<<s.maxProfit(prices);
}