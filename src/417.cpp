#include "head.h"

class Solution {
private:
    vector<vector<bool>> Preach;
    vector<vector<bool>> Areach;
    int m, n;
    void dfsP(vector<vector<int>>& heights, int x, int y) {
        if (!Preach[x][y]) {
            int pv = heights[x][y];
            Preach[x][y] = true;
            if (x > 0 && heights[x - 1][y] >= pv && !Preach[x - 1][y]) {
                dfsP(heights, x - 1, y);
            }
            if (x + 1 < m && heights[x + 1][y] >= pv && !Preach[x + 1][y]) {
                dfsP(heights, x + 1, y);
            }
            if (y + 1 < n && heights[x][y + 1] >= pv && !Preach[x][y + 1]) {
                dfsP(heights, x, y + 1);
            }
            if (y > 0 && heights[x][y - 1] >= pv && !Preach[x][y - 1]) {
                dfsP(heights, x, y - 1);
            }
        }

    }
    void dfsA(vector<vector<int>>& heights, int x, int y) {
        if (!Areach[x][y]) {
            int pv = heights[x][y];
            Areach[x][y] = true;
            if (x > 0 && heights[x - 1][y] >= pv && !Areach[x - 1][y]) {
                dfsA(heights, x - 1, y);
            }
            if (x + 1 < m && heights[x + 1][y] >= pv && !Areach[x + 1][y]) {
                dfsA(heights, x + 1, y);
            }
            if (y + 1 < n && heights[x][y + 1] >= pv && !Areach[x][y + 1]) {
                dfsA(heights, x, y + 1);
            }
            if (y > 0 && heights[x][y - 1] >= pv && !Areach[x][y - 1]) {
                dfsA(heights, x, y - 1);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->m = heights.size();
        this->n = heights[0].size();
        vector<vector<bool>> a(m, vector<bool>(n)), b(m, vector<bool>(n));
        Preach = a, Areach = b;
        for (int i = 0; i < m; i++) {
            dfsP(heights, i, 0);
        }
        for (int i = 0; i < n; i++) {
            dfsP(heights, 0, i);
        }
        for (int i = 0; i < m; i++) {
            dfsA(heights, i, n - 1);
        }
        for (int i = 0; i < n; i++) {
            dfsA(heights, m - 1, i);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (Preach[i][j] && Areach[i][j])
                    ans.push_back({ i,j });
            }
        }
        return ans;
    }
};