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
        int left, right, down, up;
        left = down = 999;
        right = up = -999;
        for (auto circle : circles) {
            left = min(left, circle[0] - circle[2]);
            right = max(right, circle[0] + circle[2]);
            down = min(down, circle[1] - circle[2]);
            up = max(up, circle[1] + circle[2]);
        }
        int ans = 0;
        for (int i = left; i <= right; i++) {
            for (int j = down; j <= up; j++) {
                for (auto pi : circles) {
                    if ((pi[0] - i) * (pi[0] - i) + (pi[1] - j) * (pi[1] - j) <= pi[2] * pi[2]) {
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