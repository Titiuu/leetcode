#include "head.h"

class Solution1 {
public:
    vector<int> countPoints(vector<vector<int>>& p, vector<vector<int>>& q) {
    	int n = q.size();
    	vector<int> ans(n, 0);
    	for(int i = 0; i < n; i++)
    	{
    		int x0 = q[i][0], y0 = q[i][1], r = q[i][2];
    		for(auto pi : p)
    		{
    			if((pi[0]-x0)*(pi[0]-x0)+(pi[1]-y0)*(pi[1]-y0) <= r*r)
    				ans[i]++; // 点在圆内
    		}
    	}
    	return ans;
    }
};

class Solution2 {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int ans = 0;
        for (int i = 0; i <= 200; i++) {
            for (int j = 0; j <= 200; j++) {
                for (auto &pi : circles) {
                    int x = pi[0], y = pi[1], r = pi[2];
                    if ((x - i) * (x - i) + (y - j) * (y - j) <= r * r) {
                        ans++; // 点在圆内
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        /* 遍历坐标系中的所有点，根据圆的方程过滤出落在圆上面的点 */
        int result = 0;
        for (int i = 0; i <= 200; i++) {
            for (int j = 0; j <= 200; j++) {
                for (auto& circle : circles) {
                    int x = circle[0], y = circle[1], r = circle[2];
                    /* 圆心为(a,b) 半径为r的圆的方程为(x-a)²+(x-b)²=r² */
                    if ((i - x) * (i - x) + (j - y) * (j - y) <= r * r) {
                        result++;
                        break;
                    }
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    int countLatticePoints(vector<vector<int>>& p) {
        set<vector<int>> ans;
        for (auto pi : p) {
            for (int i = pi[0] - pi[2]; i <= pi[0] + pi[2]; i++) {
                for (int j = pi[1] - pi[2]; j <= pi[1] + pi[2]; j++) {
                    if ((pi[0] - i) * (pi[0] - i) + (pi[1] - j) * (pi[1] - j) <= pi[2] * pi[2]) {
                        ans.insert({ i,j }); // 点在圆内
                    }
                }
            }
        }
        return ans.size();
    }
};

int main() {
    Solution S; 
    vector<vector<int>> circles = { {2, 2, 2},{3, 4, 1},{7, 1, 1} };
    S.countLatticePoints(circles);
}