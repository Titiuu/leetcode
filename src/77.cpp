#include "head.h"

class Solution {
public:
    vector<vector<int>> res;
    void backtrack(int n, int k, int start, vector<int>& track) {
        if (start == k) {
            res.emplace_back(track);
            return;
        }
        for (int i = track.empty() ? 1 : track.back() + 1; i <= n; i++) {
            track.push_back(i); //做出选择
            backtrack(n, k, start + 1, track); //回溯
            track.pop_back(); //撤销选择
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> track;
        backtrack(n, k, 0, track);
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> res = s.combine(4, 2);
    for (auto x : res) {
        cout << x[0] << " " << x[1] << " ";
    }
}