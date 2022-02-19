#include "head.h"

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ret;
        for (int n = arr.size(); n > 1; n--) {
            int index = max_element(arr.begin(), arr.begin() + n) - arr.begin();
            if (index == n - 1) {
                continue;
            }
            reverse(arr.begin(), arr.begin() + index + 1);
            reverse(arr.begin(), arr.begin() + n);
            ret.push_back(index + 1);
            ret.push_back(n);
        }
        return ret;
    }
};