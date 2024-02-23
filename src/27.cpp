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

class Solution1 {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = 0;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[j] = nums[i];
                j++;
                n++;
            }
        }
        nums.resize(n);
        return n;
    }
};

int main() {
    Solution1 s;
    vector<int> nums = { 0,1,2,2,3,0,4,2 };
    int n = s.removeElement(nums, 2);
}