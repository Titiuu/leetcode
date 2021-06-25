#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
#include <regex>
#include <cmath>
#include <numeric>
#include <unordered_map>

using namespace std;

class Solution { //官解，先枚举上下边界，再求和列生成一维数组，前缀和相减得到区间
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
        int ans = INT_MIN;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) { // 枚举上边界
            vector<int> sum(n);
            for (int j = i; j < m; ++j) { // 枚举下边界
                for (int c = 0; c < n; ++c) {
                    sum[c] += matrix[j][c]; // 更新每列的元素和
                }
                set<int> sumSet{0};
                int s = 0;
                for (int v : sum) {
                    s += v;
                    auto lb = sumSet.lower_bound(s - k);
                    if (lb != sumSet.end()) {
                        ans = max(ans, s - *lb);
                    }
                    sumSet.insert(s);
                }
            }
        }
        return ans;
    }
};