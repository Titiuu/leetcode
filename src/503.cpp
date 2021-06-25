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

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> stk;
        for (int i = 0; i < 2*n-1; i++)
        {
            int num = nums[i%n];
            while (!stk.empty() && nums[stk.top()] < num)
            {
                res[stk.top()] = num;
                stk.pop();
            }
            stk.push(i % n);
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> res, input = {1,2,1};
    res = S.nextGreaterElements(input);
    for (size_t i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<",";
    }
    
}