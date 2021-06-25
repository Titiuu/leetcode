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
    vector<vector<int>> generateMatrix(int n) {
        if (n == 1) return {{1}};
        vector<vector<int>> res(n, vector<int>(n)); //resize亦可
        int d = 0, count = 1;
        int i, j; //遍历指针
        while (d < n-1 && d < n-1)
        {
            if (d == n-1-d)
            {
                res[d][d] = count;
                return res;
            }
            for (i = 0+d, j = 0+d; j < n-1-d; j++)
                res[i][j] = count++;
            for (i = 0+d, j = n-1-d; i < n-1-d; i++)
                res[i][j] = count++;
            for (i = n-1-d, j = n-1-d; j > 0+d; j--)
                res[i][j] = count++;
            for (i = n-1-d, j = 0+d; i > 0+d; i--)
                res[i][j] = count++;
            d++;
        }
        return res;
    }
};

int main() {
    Solution S;//{{1,2,3},{4,5,6},{7,8,9}}
    vector<vector<int>> res = S.generateMatrix(5);
    for (auto i:res) {
        for (auto j:i)
            cout<<j<<' ';
        cout<<endl;
    }
}