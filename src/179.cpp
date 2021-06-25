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
    string largestNumber(vector<int>& nums) {
        int flag = 0;
        for (int i:nums) {
            if (i != 0) {
                flag++;
                break;
            }
        }
        if (flag == 0)  return "0";
        vector<string> box(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            box[i] = to_string(nums[i]);
        }
        sort(box.begin(), box.end(), [](string i, string j) {
            string m = i + j, n = j + i;
            if (atoi(m.c_str()) > atoi(n.c_str()))
                return true;
            return false;
        });
        string s;
        for (auto i : box) {
            s += i;
        }
        return s;
    }
};