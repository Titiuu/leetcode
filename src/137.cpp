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
#include <set>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        for (int i : nums) {
            if (hashmap.find(i) == hashmap.end()) {
                hashmap.insert(pair(i, 1));
            }
            else {
                hashmap[i]++;
            }
        }
        for (auto i : hashmap) {
            if (i.second == 1) {
                return i.first;
            }
        }
        return 0;
    }
};