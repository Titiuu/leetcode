#include "head.h"

class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int p, int q) { // (p,q)代表初始位置
        visited[p][q] = 1;
        if (p + 1 < grid.size() && grid[p + 1][q] == '1' && visited[p + 1][q] == 0) // down
            dfs(grid, visited, p + 1, q);
        if (q + 1 < grid[0].size() && grid[p][q + 1] == '1' && visited[p][q + 1] == 0) // right
            dfs(grid, visited, p, q + 1);
        if (p - 1 >= 0 && grid[p - 1][q] == '1' && visited[p - 1][q] == 0) // up
            dfs(grid, visited, p - 1, q);
        if (q - 1 >= 0 && grid[p][q - 1] == '1' && visited[p][q - 1] == 0) //left
            dfs(grid, visited, p, q - 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0)); // 0 means not visited
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 0 && grid[i][j] == '1') { // 未浏览到
                    dfs(grid, visited, i, j);
                    res++;
                }
            }
        }
        return res;
    }
};

int main() {
    vector<vector<char>> grid { {'1','1','1'}, {'0','1','0'}, {'1','1','1'} };
    Solution s;
    cout << s.numIslands(grid);
}