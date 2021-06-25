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
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (auto i:tokens) {
            if (i == "+") {
                int i = stk.top();
                stk.pop();
                int j = stk.top();
                stk.pop();
                stk.push(j + i);
            }
            else if (i == "-") {
                int i = stk.top();
                stk.pop();
                int j = stk.top();
                stk.pop();
                stk.push(j - i);   
            }
            else if (i == "*") {
                int i = stk.top();
                stk.pop();
                int j = stk.top();
                stk.pop();
                stk.push(j * i); 
            }
            else if (i == "/") {
                int i = stk.top();
                stk.pop();
                int j = stk.top();
                stk.pop();
                stk.push(j / i);
            }
            else {
                stk.push( stoi(i) );
            }
        }
        return stk.top();
    }
};