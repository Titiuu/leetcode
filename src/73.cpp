#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <regex>
#include <cmath>
#include <numeric>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool row0 = false, column0 = false;
        //记录第一行和第一列是否有0
        for (int i = 0; i < m; i++) {
            if (!matrix[i][0]) {
                column0 = true;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (!matrix[0][i]) {
                row0 = true;
                break;
            } 
        }
        //用第一列和第一行记录全局的0的情况
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
            {
                if (!matrix[i][j])
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        //根据第一列和第一行赋0
        for (int i = 1; i < m; i++) {
            if (!matrix[i][0]) {
                for (int j = 1; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < n; i++) {
            if (!matrix[0][i]) {
                for (int j = 1; j < m; j++) {
                    matrix[j][i] = 0;
                }
            } 
        }
        //还原
        if (column0)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        if (row0)
            for (int i = 0; i < n; i++)
                matrix[0][i] = 0;
    }
};

int main() {
    vector<vector<int>> res = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    Solution S;
    S.setZeroes(res);
    for (auto i:res) {
        for (auto j:i) {
            printf("%d,",j);
        }
        printf("\b\n");
    }
}