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

class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i + 1;
    }
};