#include "head.h"

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid[0].size(), m = grid.size();  //m行n列
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int ballState = 0;  //0表示球从上往下落，1表示球水平向左移动，2表示水平向右移动，3表示卡住
            int preM = 0, preN = i;  //当前行和列 
            while (preM != m) {
                if (ballState == 0 && grid[preM][preN] == -1) {
                    ballState = 1;
                    preN--;
                    if (preN == -1) {
                        ballState = 3;
                        break;
                    }
                }
                else if (ballState == 0 && grid[preM][preN] == 1) {
                    ballState = 2;
                    preN++;
                    if (preN == n) {
                        ballState = 3;
                        break;
                    }
                }
                else if (ballState == 1 && grid[preM][preN] == -1) {
                    ballState = 0;
                    preM++;
                }
                else if (ballState == 1 && grid[preM][preN] == 1) {
                    ballState = 3;
                    break;
                }
                else if (ballState == 2 && grid[preM][preN] == -1) {
                    ballState = 3;
                    break;
                }
                else if (ballState == 2 && grid[preM][preN] == 1) {
                    ballState = 0;
                    preM++;
                }
            }
            if (preM == m)
                ans.push_back(preN);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};