#include "head.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int preMin = prices[0], ans = 0;
        for (int i = 0; i < n - 1; i++) {
            preMin = min(preMin, prices[i]);
            ans = max(ans, prices[i + 1] - preMin);            
        }
        return ans;
    }
};

class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int leftMin = 1e9, ans = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            leftMin = min(prices[i], leftMin);
            ans = max(prices[i]-leftMin, ans);
        }
        return ans;
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int leftMin = 1e9, ans = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            leftMin = min(prices[i], leftMin);
            ans = max(prices[i]-leftMin, ans);
        }
        return ans;
    }
};