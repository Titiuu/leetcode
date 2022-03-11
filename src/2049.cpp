#include "head.h"

class Solution {
private:
    long maxScore = 0;
    int cnt = 0;
    int n;
    vector<vector<int>> children;
    
    int dfs(int Node) {
        long score = 1;
        int sum = 1;
        for (int num : children[Node]) {
            int remains = dfs(num);
            score *= remains;
            sum += remains;
        }
        if (Node != 0) {
            score *= n - sum;
        }
        if (maxScore == score) {
            cnt++;
        } else if (maxScore < score) {
            maxScore = score;
            cnt = 1;
        }
        return sum;
    }
    
public:
    int countHighestScoreNodes(vector<int>& parents) {
        this->n = parents.size();
        this->children = vector<vector<int>>(n);
        for (int i = 0; i < n; i++) {
            if (parents[i] != -1)
                this->children[parents[i]].emplace_back(i);
        }
        dfs(0);
        return cnt;
    }
};
