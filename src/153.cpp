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
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n==1)   return nums[0];
        if (nums[0]<nums[n-1])  return nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i+1]<nums[i])
            {
                return nums[i+1];
            }
        }
        return nums[0];
    }
};