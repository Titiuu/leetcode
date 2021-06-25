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
    bool find132pattern(vector<int>& nums) {
        int two = INT_MIN;
        // 保存3的单调栈，从底到顶递减
        stack<int> s;
        int n = nums.size();
        for (int i = n-1; i >=0; --i)
        {
            // 找到比2小的数字，那么满足条件
            if (nums[i] >= two)
            {
                // 如果发现大于栈顶（破坏了单调性），那么要去更新栈和two的数值（two变为更大的数字）
                while (!s.empty() && nums[s.top()] < nums[i])
                {
                    two = nums[s.top()];
                    s.pop();
                }

                s.push(i);
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};