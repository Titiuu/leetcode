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
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> jobs;
    int n, k;
    int ans = 0x3f3f3f3f;
    int minimumTimeRequired(vector<int>& _jobs, int _k) {
        jobs = _jobs;
        n = jobs.size();
        k = _k;
        vector<int> sum(k);
        dfs(0, 0, sum, 0);
        return ans;
    }
    /**
     * u     : 当前处理到那个 job
     * used  : 当前分配给了多少个工人了
     * sum   : 工人的分配情况          例如：sum[0] = x 代表 0 号工人工作量为 x
     * max   : 当前的「最大工作时间」
     */
    void dfs(int u, int used, vector<int> sum, int maxT) {
        if (maxT >= ans) return;  //大于当前最大时间直接回溯
        if (u == n) {
            ans = maxT;  //深搜中不断更新最小的最大时间
            return;
        }
        // 优先分配给「空闲工人」
        if (used < k) {
            sum[used] = jobs[u];
            dfs(u + 1, used + 1, sum, max(sum[used], maxT));
            sum[used] = 0;
        }
        for (int i = 0; i < used; i++) {
            sum[i] += jobs[u];
            dfs(u + 1, used, sum, max(sum[i], maxT));
            sum[i] -= jobs[u];
        }
    }
};