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