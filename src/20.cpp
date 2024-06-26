#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <regex>
#include <cmath>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> box;
        for (size_t i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
            case ')':
                if (box.empty()) return false;
                if (box.top() != '(')
                    return false;
                box.pop();
                break;
            case ']':
                if (box.empty()) return false;
                if (box.top() != '[')
                    return false;
                box.pop();
                break;
            case '}':
                if (box.empty()) return false;
                if (box.top() != '{')
                    return false;
                box.pop();
                break;
            default:
                box.push(s[i]);
                break;
            }
        }
        if (box.empty())    return true;
        return false;
    }
};

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto c : s) {
            if (c == ')') {
                if (stk.top() != '(')
                    return false;
                stk.pop();
            }
            else if (c == ']') {
                if (stk.top() != '[')
                    return false;
                stk.pop();
            }
            else if (c == '}') {
                if (stk.top() != '{')
                    return false;
                stk.pop();
            }
            else {
                stk.push(c);
            }
        }
        return stk.empty();
    }
};

int main() {
    Solution S;
    cout<<S.isValid("()");
}