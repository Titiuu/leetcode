#include "head.h"

class Solution {
private:
    vector<int> nums;
    int maxOr, cnt;
    
public:
    int countMaxOrSubsets(vector<int>& nums) {
        this->nums = nums;
        this->maxOr = 0;
        this->cnt = 0;
        dfs(0, 0);
        return cnt;
    }

    void dfs(int pos, int orVal) {
        if (pos == nums.size()) {  //判断搜索完毕
            if (orVal > maxOr) {
                maxOr = orVal;
                cnt = 1;
            } else if (orVal == maxOr) {
                cnt++;
            }
            return;
        }
        dfs(pos + 1, orVal| nums[pos]);  //两种选择
        dfs(pos + 1, orVal);
    }
};