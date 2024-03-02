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

class Solution { //KMP
public:
    int strStr(string s, string p) {
        int n = s.size(), m = p.size();
        if(m == 0) return 0;
        //设置哨兵
        s.insert(s.begin(),' ');
        p.insert(p.begin(),' ');
        vector<int> next(m + 1);
        //预处理next数组
        for(int i = 2, j = 0; i <= m; i++){
            while(j && p[i] != p[j + 1]) j = next[j];
            if(p[i] == p[j + 1]) j++;
            next[i] = j;
        }
        //匹配过程
        for(int i = 1, j = 0; i <= n; i++){
            while(j && s[i] != p[j + 1]) j = next[j];
            if(s[i] == p[j + 1]) j++;
            if(j == m) return i - m;
        }
        return -1;
    }
};

class Solution1 {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};