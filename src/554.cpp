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
    int leastBricks(vector<vector<int>>& wall) {
        int len = 0;
        int n = wall.size();
        for (int i : wall[0]) {
            len += i;
        }
        if (len == 1)   return n;
        unordered_map<int, int> map;
        for (auto i : wall) {
            int site = -1;
            for (int j = 0; j < i.size()-1; j++) {
                site += i[j];
                map[site]++; //map默认构造为0
            }
        }
        int max = 0;
        for (pair<int, int> p : map) {
            if (p.second > max)
                max = p.second;
        }
        return n - max;
    }
};

int main() {
    Solution S;
    vector<vector<int>> bricks = {{1,2,2,1},{3,1,2},{1,3,2},{2,4},{3,1,2},{1,3,1,1}};
    cout << S.leastBricks(bricks);
}