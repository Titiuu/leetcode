#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <regex>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index = -1;
        int n = nums.size();
        int i = 0, j = n - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (target > nums[mid]) {
                i = mid + 1;
            }
            else if (target < nums[mid]) {
                j = mid - 1;
            }
            else {
                index =  mid;
                break;
            }
        }
        if (index == -1)    return 0;
        i = index, j = index + 1;
        int count = 0;
        while (i >= 0 && nums[i] == target) {
            i--;
            count++;
        }
        while (j < n && nums[j] == target) {
            j++;
            count++;
        }
        return count;
    }
};