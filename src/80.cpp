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
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator i = nums.begin(), j = i + 1, k = i + 2;
        while (k < nums.end()) {
            if (*i == *j && *i == *k) {
                nums.erase(k);
            }
            else {
                i++, j++, k++;
            }
        }
        return nums.size();
    }
};

class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return n;
        int i = 0, j = 1;
        for (int k = 2; k < n; k++) {
            if (nums[k] != nums[i] || nums[k] != nums[j]) {
                nums[j + 1] = nums[k];
                i++;
                j++;
            }
        }
        return j + 1;
    }
};