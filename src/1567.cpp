#include "head.h"

class Solution {
private:
    int getMaxLenNoZero(vector<int>& nums) {
        int n = nums.size();
        int flag = 1;
        for (auto x : nums) {
            flag *= x / abs(x);
        }
        if (flag == 1)  return n;
        for (int i = 0; i < n / 2; i++) {
            if (nums[i] < 0 || nums[n-1-i] < 0)
                return n - i - 1;
        }
        return 0;        
    }
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        vector<int> zeroIndex;
        int count = 0;  //对0的个数计数
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeroIndex.push_back(i);
                count++;
            }
        }
        if (count == 0)
            return getMaxLenNoZero(nums);
        vector<int> possibleAns;
        int first = -1, second = zeroIndex[0];
        for (int i = 0; i < count; i++) {
            vector<int> temp(nums.begin() + first + 1, nums.begin() + second);
            possibleAns.push_back(getMaxLenNoZero(temp));
            first = second;
            if (i + 1 == count)    break;
            second = zeroIndex[i + 1];
        }
        vector<int> temp(nums.begin() + first + 1, nums.end());
        possibleAns.push_back(getMaxLenNoZero(temp));
        return *max_element(possibleAns.begin(), possibleAns.end());
    }
};