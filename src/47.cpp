#include "head.h"

class Solution {
private:
    vector<vector<int>> res;
    vector<int> l;
    vector<bool> visited;
    int n;
    void backtrack(vector<int>& nums) {
        if (l.size() == n) {
            res.emplace_back(l);
            return;
        }
        for (int i = 0; i < n; i++) {
            //一些逻辑操作（可有可无，视情况而定）
            if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])) {
                continue;
            }

            l.emplace_back(nums[i]);
            visited[i] = true;
            backtrack(nums);
            //撤销选择
            l.pop_back();
            visited[i] = false;

        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        visited.resize(n, false);
        vector<int> start;
        backtrack(nums);
        return res;
    }
};