#include "head.h"

class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int p, int q, int& flag) {
        if (p >= board.size() || p < 0 || q >= board[0].size() || q < 0) {
            flag = 1;
            return;
        }
        if (board[p][q] == 'X')
            return;
        if (visited[p][q] == 1)
            return;
        dfs(board, visited, p + 1, q, flag);
        dfs(board, visited, p - 1, q, flag);
        dfs(board, visited, p, q + 1, flag);
        dfs(board, visited, p, q - 1, flag);
    }
    void dfsPaint(vector<vector<char>>& board, vector<vector<int>>& visited, int p, int q) {
        if (p >= board.size() || p < 0 || q >= board[0].size() || q < 0) {
            return;
        }
        if (visited[p][q] == 0)
            return;
        if (visited[p][q] == 2)
            return;
        visited[p][q] = 2;
        board[p][q] = 'X';
        dfsPaint(board, visited, p + 1, q);
        dfsPaint(board, visited, p - 1, q);
        dfsPaint(board, visited, p, q + 1);
        dfsPaint(board, visited, p, q - 1);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0)); // 0 means not visited
        vector<vector<int>> starts;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 0 && board[i][j] == 'O') { // 未浏览到
                    int flag = 0;
                    dfs(board, visited, i, j, flag);
                    if (flag == 0)
                        dfsPaint(board, visited, i, j);
                }
            }
        }
    }
};