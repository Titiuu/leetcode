#include "head.h"

class Solution {
private:
    int find(vector<int>& fa, int p) { //查找p的fa，默认p合法
        if (fa[p] != p) {
            fa[p] = find(fa, fa[p]);
        }
        return fa[p];
    }

    void unio(vector<int>& fa, int p, int q) {
        fa[find(fa, p)] = find(fa, q);
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> fa(n, 0);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j])
                    unio(fa, i, j);
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (fa[i] == i) {
                res++;
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> isC { {1,0,0,1}, {0,1,1,0 }, {0, 1, 1, 1}, {1, 0, 1, 1} };
    Solution s;
    cout << s.findCircleNum(isC);
}