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
#include <unordered_map>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i, j;
        for (i = 0, j = 0; j < nums.size();)
        {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++, j++;
            }
            else j++;
        }
        return i;
    }
};