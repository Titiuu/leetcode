#include "head.h"

class Solution { //建议排序做，提前超过就剪枝
private:
    vector<vector<int>> res;
    vector<int> ans;
    int sum;
    void backtrack(vector<int> candidates, int preSum, int begin) {
        //终止条件(递归必须要有终止条件)
        // if (preSum > sum) {
        //     return;
        // }
        if (preSum == sum) {
            res.push_back(ans);
            return;
        }

        for (int i = begin; i < candidates.size(); i++) {
            //做出选择
            if (preSum + candidates[i] > sum)
                continue;
            preSum += candidates[i];
            ans.emplace_back(candidates[i]);
            //递归
            backtrack(candidates, preSum, i);
            //一些逻辑操作（可有可无，视情况而定）
            preSum -= candidates[i];
            ans.pop_back();
            //撤销选择
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sum = target;
        backtrack(candidates, 0, 0);
        return res;
    }
};

//*************************************************************************
class Solution1 {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& candidates, int start, vector<int>& track, int& target) {
        if (target == 0) {
            res.emplace_back(track);
            return;
        }
        if (target < 0)
            return;
        for (int i = start; i < candidates.size(); i++) {
            track.push_back(candidates[i]); //做出选择
            target -= candidates[i];
            backtrack(candidates, i, track, target); //回溯
            track.pop_back(); //撤销选择
            target += candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> track;
        backtrack(candidates, 0, track, target);
        return res;
    }
};

int main() {
    Solution1 S;
    vector<int> c = { 2,7,6,3,5,1 };
    S.combinationSum(c, 9);
}