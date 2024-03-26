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
            if (!visited[i]) {
                l.emplace_back(nums[i]);
                visited[i] = true;
                backtrack(nums);
                //撤销选择
                l.pop_back();
                visited[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        visited.resize(n, false);
        vector<int> start;
        backtrack(nums);
        return res;
    }
};


//**************************************************************
class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, int start, vector<int>& track, vector<int>& visited) {
        if (start == nums.size()) {
            res.emplace_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] == 0) {
                track.push_back(nums[i]); //做出选择
                visited[i] = 1;
                backtrack(nums, start + 1, track, visited); //回溯
                track.pop_back(); //撤销选择
                visited[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> visited(n, 0); // 0 means unvisited
        vector<int> track;
        backtrack(nums, 0, track, visited);
        return res;
    }
};