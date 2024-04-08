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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rows = matrix.size();
        int columns = matrix[0].size();
        int i, j, d = 0;
        if (rows == 1)
        {
            return matrix[0];
        }
        if (columns == 1)
        {
            for (int i = 0; i < matrix.size(); i++)
                res.push_back(matrix[i][0]);
            return res;
        }
        while (d < rows-1 && d < columns-1)
        {
            if (d == rows-1-d)
            {
               for (int k = d; k <= columns-1-d; k++)
                   res.push_back(matrix[d][k]);
                return res;
            }
            if (d == columns-1-d)
            {
                for (int k = d; k <= rows-1-d; k++)
                    res.push_back(matrix[k][d]);
                return res;
            }
            for (i = 0+d, j = 0+d; j < columns-1-d; j++)
                res.push_back(matrix[i][j]);
            for (i = 0+d, j = columns-1-d; i < rows-1-d; i++)
                res.push_back(matrix[i][j]);
            for (i = rows-1-d, j = columns-1-d; j > 0+d; j--)
                res.push_back(matrix[i][j]);
            for (i = rows-1-d, j = 0+d; i > 0+d; i--)
                res.push_back(matrix[i][j]);
            d++;
        }
        return res;
    }
};

class Solution1 {
public:
    int up, left, down, right; // 边界
    vector<int> res;
    void walk(vector<vector<int>>& matrix, int& p, int& q, int direction) {
        if (direction == 0) {
            while (q != right) {
                res.push_back(matrix[p][q]);
                q++;
            }
            up++;
        }
        else if (direction == 1) {
            while (p != down) {
                res.push_back(matrix[p][q]);
                p++;
            }
            right--;
        }
        else if (direction == 2) {
            while (q != left) {
                res.push_back(matrix[p][q]);
                q--;
            }
            down--;
        }
        else if (direction == 3) {
            while (p != up) {
                res.push_back(matrix[p][q]);
                p--;
            }
            left++;
        }
        else {
            cout << "invalid direction!" << endl;
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        up = 0, left = 0, down = m - 1, right = n - 1; // 边界
        int direction = 0; // 方向
        int p = 0, q = 0; // 起始位置
        int len = -1;
        while (1) {
            walk(matrix, p, q, direction);
            direction = (direction + 1) % 4;
            if (len == res.size())
                break;
            len = res.size();
        }
        res.push_back(matrix[p][q]);
        return res;
    }
};

int main() {
    Solution1 S;//{{1,2,3},{4,5,6},{7,8,9}}
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};//{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}
    vector<int> res = S.spiralOrder(mat);
    for (auto i:res)
        cout<<i<<',';
}