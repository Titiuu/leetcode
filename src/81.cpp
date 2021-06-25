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
    bool search(vector<int>& nums, int target) {
        if (target > nums[0]) {
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i]==target)    return true;
            }
        }
        else {
            for (int i = nums.size() - 1; i > -1; i--)
            {
                if (nums[i]==target)    return true;
            }
        }
        return false;
    }
};