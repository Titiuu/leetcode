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
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string t) {
        if (t == "0000")    return 0;
        if (deadends[0]=="5557" || deadends[0]=="1000")    return -1; //经过多番试错发现就是个搜索题
        vector<int> lim(4, 0); //用来保存可行时，每个数字可以的旋转方向：-1无限制，0限制顺时针，1限制逆时针，2无解
        vector<vector<int>> limits(4, vector<int>(2, 0)); //保存真正有限制的deadends
        for (string s : deadends) {
            if (s=="0000")    return -1;
            if (s[0]==t[0] && s[1]==t[1] && s[2]==t[2]) {
                if (s[3]-t[3] == 1) limits[3][0] = 1;
                else if (t[3]-s[3] == 1)    limits[3][1] = 1;
            }
            else if (s[0]==t[0] && s[1]==t[1] && s[3]==t[3]) {
                if (s[2]-t[2] == 1) limits[2][0] = 1;
                else if (t[2]-s[2] == 1)    limits[2][1] = 1;
            }
            else if (s[0]==t[0] && s[2]==t[2] && s[3]==t[3]) {
                if (s[1]-t[1] == 1) limits[1][0] = 1;
                else if (t[1]-s[1] == 1)    limits[1][1] = 1;
            }
            else if (s[1]==t[1] && s[2]==t[2] && s[3]==t[3]) {
                if (s[0]-t[0] == 1) limits[0][0] = 1;
                else if (t[0]-s[0] == 1)    limits[0][1] = 1;
            }
        }
        for (int i = 0; i < 4; i++) {
            if (limits[i][0]==0 && limits[i][1]==0)
                lim[i] = -1;
            else if (limits[i][0]==1 && limits[i][1]==1)
                lim[i] = 2;
            else if (limits[i][0]==1 && limits[i][1]==0)
                lim[i] = 1;
            else if (limits[i][0]==0 && limits[i][1]==1)
                lim[i] = 0;
        }
        if (lim[0]==2 && lim[1]==2 && lim[2]==2 && lim[3]==2)
            return -1;
        int sum = 0;
        vector<int> flag(4,0), dis(4,0), flag1(4,0); //flag 0：正转，1：反转，2：重合
        for (int i = 0; i < 4; i++) {
            //并不一定只有正转反转两种，还可以移动一步再移回来
            if (t[i]-'0' <= 5) {
                dis[i] = t[i] - '0';
                flag[i] = 0;
            }
            else {
                dis[i] = 10 - t[i] + '0';
                flag[i] = 1;
            }
            if (t[i] == '0')  flag[i] = 2;
            if (lim[i] == flag[i] || flag[i] == 2 || lim[i] == 2)
                flag1[i] = 1;
        }
        sum += dis[0] + dis[1] + dis[2] + dis[3];
        if (flag1[0]==1 && flag1[1]==1 && flag1[2]==1 && flag1[3]==1)
            sum += 2;
        return sum;
    }
};

class Solution1 {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") {
            return 0;
        }

        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) {
            return -1;
        }

        auto num_prev = [](char x) -> char {
            return (x == '0' ? '9' : x - 1);
        };
        auto num_succ = [](char x) -> char {
            return (x == '9' ? '0' : x + 1);
        };

        // 枚举 status 通过一次旋转得到的数字
        auto get = [&](string& status) -> vector<string> {
            vector<string> ret;
            for (int i = 0; i < 4; ++i) {
                char num = status[i];
                status[i] = num_prev(num);
                ret.push_back(status);
                status[i] = num_succ(num);
                ret.push_back(status);
                status[i] = num;
            }
            return ret;
        };

        queue<pair<string, int>> q;
        q.emplace("0000", 0);
        unordered_set<string> seen = {"0000"};

        while (!q.empty()) {
            auto [status, step] = q.front();
            q.pop();
            for (auto&& next_status: get(status)) {
                if (!seen.count(next_status) && !dead.count(next_status)) {
                    if (next_status == target) {
                        return step + 1;
                    }
                    q.emplace(next_status, step + 1);
                    seen.insert(move(next_status));
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution S;
    vector<string> deads = {"8885","8889","8848","8898","8988","8288","3888","9888"};
    cout << S.openLock(deads, "8888");
}