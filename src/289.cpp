#include "head.h"

class Solution {
public:
    int count(vector<vector<int>>& board, int p, int q) {
        int m = board.size(), n = board[0].size();
        int res = 0;
        if (p > 0 && board[p - 1][q] == 1) res++;
        if (p > 0 && q > 0 && board[p - 1][q - 1] == 1) res++;
        if (p > 0 && q < n - 1 && board[p - 1][q + 1] == 1) res++;
        if (p < m - 1 && board[p + 1][q] == 1) res++;
        if (p < m - 1 && q > 0 && board[p + 1][q - 1] == 1) res++;
        if (p < m - 1 && q < n - 1 && board[p + 1][q + 1] == 1) res++;
        if (q > 0 && board[p][q - 1] == 1) res++;
        if (q < n - 1 && board[p][q + 1] == 1) res++;
        return res;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> alive(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = count(board, i, j);
                if ((cnt == 2 && board[i][j] == 1) || (cnt == 3))
                    alive[i][j] = true;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                alive[i][j] == true ? board[i][j] = 1 : board[i][j] = 0;
            }
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> board { {0,1,0},{0,0,1},{1,1,1},{0,0,0} };
    s.gameOfLife(board);
}