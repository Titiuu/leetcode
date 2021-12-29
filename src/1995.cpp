#include "head.h"

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        // vector<pair<int, int>> value_indexs(nums.size());
        // for (int i = 0; i < nums.size(); i++) {
        //     value_indexs[i] = {nums[i], i};
        // }
        // sort(value_indexs.begin(), value_indexs.end(), [](const pair<int, int> &a, const pair<int, int> &b){
        //     return a.first < b.first;
        // });
        // sort(nums.begin(), nums.end());
        int i, j, k, l, count = 0, len = nums.size();
        for (i = 0; i < len - 3; i++) {
            for (j = i + 1; j < len - 2; j++) {
                for (k = j + 1; k < len - 1; k++) {
                    for (l = k + 1; l < len; l++)
                        if (nums[i] + nums[j] + nums[k] == nums[l])
                            count ++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution S;
    vector<int> n = {1, 1, 1, 3, 5, 8, 6, 3, 7};
    cout << S.countQuadruplets(n);
}