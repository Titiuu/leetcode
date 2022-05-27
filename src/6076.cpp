#include "head.h"

class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n = stockPrices.size();
        if (n == 1)  return 0;
        sort(stockPrices.begin(), stockPrices.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
            });
        int res = 0;
        vector<int> t = stockPrices[0];
        for (int i = 1; i < n; i++) {
            long long x = t[0], y = t[1];
            long long dy = stockPrices[i][1] - y, dx = stockPrices[i][0] - x;
            while (i < n - 1 && dx * (stockPrices[i + 1][1] - y) == dy * (stockPrices[i + 1][0] - x)) {
                i++;
            }
            res++;
            if (i == n)
                return res;
            else {
                t = stockPrices[i];
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<vector<int>> stock = { {3,4},{1,2},{7,9},{2,3} };
    cout << S.minimumLines(stock);
    return 0;
}