#include "head.h"

class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int jump = n / 20;
        int sum = 0;
        for (int i = jump; i < n - jump; i++) {
            sum += arr[i];
        }
        return double(sum) / double((n - 2 * jump));
    }
};