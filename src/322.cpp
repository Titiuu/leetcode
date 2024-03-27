#include "head.h"

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (auto& x : coins) {
                if (i - x >= 0)
                    if (dp[i - x] != -1) {
                        if (dp[i] == -1)
                            dp[i] = dp[i - x] + 1;
                        else
                            dp[i] = min(dp[i], dp[i - x] + 1);
                    }
            }
        }
        return dp[amount];
    }
};

int main() {
    vector<int> coins { 1,2,5 };
    Solution s;
    cout << s.coinChange(coins, 11);
}