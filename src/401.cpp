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
    static unordered_map<int,vector<string>> mp;
    static int cnt;
    static int getCnt(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) ans++;
        return ans;
    }
    static int lowbit(int x) {
        return x & -x;
    }
    static void PreTable(){
        //cout <<"test:" << cnt << endl; //这里可以看到只加载一次 
        cnt++;
        for (int h = 0; h <= 11; h++) {
            for (int m = 0; m <= 59; m++) {
                int tot = getCnt(h) + getCnt(m);
                char buffer[6];
                sprintf(buffer,"%d:%02d",h,m);
                mp[tot].push_back(buffer);
            }
        }
    }

    vector<string> readBinaryWatch(int turnedOn) {
        if(cnt == 1) PreTable();
        return mp[turnedOn];
    }
};

int Solution::cnt = 1;
unordered_map<int,vector<string>> Solution::mp = {};