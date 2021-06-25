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
    int removeDuplicates(vector<int>& nums) {
        int i, j;
        for (i = 0, j = 1; j < nums.size();) {
            if (nums[i]==nums[j]) {
                nums.erase(nums.begin()+j); //用覆盖速度快
            }
            else {
                 i++, j++;
            }
        }
        return nums.size();
    }
};