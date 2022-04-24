#include "head.h"

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) {
            if (a[0] != b[0])
                return	a[0] < b[0];
            else
                return a[1] < b[1];
            });
        vector<int> ans(points.size(), 0);
        for (int i = 0; i < rectangles.size(); i++) {
            for (auto p : points) {
                if (p[0] <= rectangles[i][0] && p[1] <= rectangles[i][1])
                    ans[i]++;
                else
                    break;
            }
        }
        return ans;
    }
};