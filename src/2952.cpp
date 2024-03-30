#include "head.h"

class Solution {
public:
    int minimumAddedCoins(vector<int> &coins, int target) {
        sort(coins.begin(),coins.end());
        int ans = 0, s = 1, i = 0;
        while (s <= target) {
            if (i < coins.size() && coins[i] <= s) {
                s += coins[i++];
            } else {
                s *= 2; // 必须添加 s
                ans++;
            }
        }
        return ans;
    }
};