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
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> map;
        for (string i : words) {
            map[i]++;
        }
        vector<pair<string, int>> res;
        for (auto i : map) {
            res.push_back(i);
        }
        sort(res.begin(), res.end(), [](const pair<string,int> & a,const pair<string,int> & b){
            if (a.second != b.second)
                return a.second > b.second;
            else
                return a.first < b.first;
        });
        vector<string> re(k);
        for (int i = 0; i < k; i++) {
            re[i] = res[i].first;
        }
        return  re;
    }
};