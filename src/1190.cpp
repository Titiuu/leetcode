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
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> pair(n);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                int j = stk.top();
                stk.pop();
                pair[i] = j, pair[j] = i;
            }
        }

        string ret;
        int index = 0, step = 1;
        while (index < n) {
            if (s[index] == '(' || s[index] == ')') {
                index = pair[index];
                step = -step;
            } else {
                ret.push_back(s[index]);
            }
            index += step;
        }
        return ret;
    }
};

class Solution1 {
public:
    string reverseParentheses(string s) {
        string rst, str;
        for(auto c:s){
            if(c != ')')
                rst.push_back(c);
            else{
                while(rst.back() != '('){
                    str.push_back(rst.back());
                    rst.pop_back();
                }
                rst.pop_back();
                rst += str;
                str.clear();
            }
        }
        return rst;
    }
};

int main() {
    Solution S;
    cout << S.reverseParentheses("(ed(et(oc))el)");
    return 0;
}