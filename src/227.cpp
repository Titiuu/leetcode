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
    int calculate(string s) {
        vector<int> nums;
        int i = 0, num = 0, sign = 1, prenum = 0, backnum = 0;
        while (i < s.size()) {
            switch (s[i])
            {
            case '+':
                sign = 1;
                i++;
                break;
            case ' ':
                i++;
                break;
            case '-':
                sign = -1;
                i++;
                break;
            case '*':
                while(s[i]<0x30 || s[i]>0x39)
                    i++;
                while (0x30<=s[i] && s[i]<=0x39) {
                    backnum = backnum * 10 + (s[i]-0x30) ;
                    i++;
                }
                prenum = nums.back();
                nums.pop_back();
                nums.push_back( prenum * backnum);
                backnum = 0;
                break;
            case '/':
                while(s[i]<0x30 || s[i]>0x39)
                    i++;
                while (0x30<=s[i] && s[i]<=0x39) {
                    backnum = backnum * 10 + (s[i]-0x30) ;
                    i++;
                }
                prenum = nums.back();
                nums.pop_back();
                nums.push_back( prenum / backnum);
                backnum = 0;
                break;
            default:
                while (0x30<=s[i] && s[i]<=0x39) {
                    num = num * 10 + (s[i]-0x30);
                    i++;
                }
                nums.push_back(num * sign);
                num = 0;
                break;
            }
        }
        return accumulate(nums.begin(),nums.end(),0); 
    }
};

int main() {
    Solution S;
    cout<<S.calculate("31+5*24/2");
}