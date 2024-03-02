#include "head.h"

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;  //双指针
        int leftMax = 0, rightMax = 0;  //当前左右侧的最高值
        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (leftMax < rightMax) {  //对于当前左侧小于右侧的情况，那么能装多少水取决于
                ans += leftMax - height[left];
                left++;
            } else {
                ans += rightMax - height[right];
                right--;
            }
        }
        return ans;
    }
};

class Solution1 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> level(n, 0);
        int i = 0, j = n - 1, maxHeight = 0;
        while (i < j) {
            int preHeight = min(height[i], height[j]);
            if (preHeight > maxHeight)
                for (int k = i + 1;k < j;k++) {
                    level[k] = preHeight;
                }
            if (height[i] < height[j]) {
                maxHeight = max(height[i], maxHeight);
                i++;
                level[i] = level[i] - height[i] > 0 ? level[i] - height[i] : 0;
            }
            else {
                maxHeight = max(height[j], maxHeight);
                j--;
                level[j] = level[j] - height[j] > 0 ? level[j] - height[j] : 0;
            }
        }
        return accumulate(level.begin(), level.end(), 0);
    }
};

int main() {
    Solution1 s;
    vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    cout << s.trap(height);
}