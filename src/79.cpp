#include "head.h"

class Solution {
public:
    int flag = 0;
    vector<vector<int>> directions { {1,0},{-1,0},{0,1},{0,-1} };
    void dfs(vector<vector<char>>& board, string& word, int start, int p, int q, vector<vector<int>>& visited) { // start used to count NO. char in word
        if (start == word.size()-1 && board[p][q] == word[start]) {
            flag = 1;
            return;
        }
        if (board[p][q] != word[start])
            return;
        for (int i = 0; i < 4; i++) {
            if (p + directions[i][0] >= 0 && p + directions[i][0] < board.size() && q + directions[i][1] >= 0 && q + directions[i][1] < board[0].size())
                if (visited[p + directions[i][0]][q + directions[i][1]] == 0) {
                    visited[p + directions[i][0]][q + directions[i][1]] = 1;
                    dfs(board, word, start + 1, p + directions[i][0], q + directions[i][1], visited);
                    visited[p + directions[i][0]][q + directions[i][1]] = 0;
                }
        }
    }
        bool exist(vector<vector<char>>&board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<int>> visited(m, vector<int>(n, 0)); // 0 means unvisited
                    visited[i][j] = 1;
                    dfs(board, word, 0, i, j, visited);
                    if (flag == 1)
                        return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board { {'A','B','C','D'},{'S','F','C','E'},{'A','S','E','E'} };
    string word = "ABCCED";
    cout << s.exist(board, word);
}