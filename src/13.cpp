#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <regex>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result=0;
        // map<char, int> hashlist = {
        //     {'I', 1},
        //     {'V', 5},
        //     {'X', 10},
        //     {'L', 50},
        //     {'C', 100},
        //     {'D', 500},
        //     {'M', 1000}}; //初始化哈希表
        auto hashlist = [](char c){
            switch (c)
            {
            case 'I':
                return 1;
                break;
            case 'V':
                return 5;
                break;
            case 'X':
                return 10;
                break;
            case 'L':
                return 50;
                break;
            case 'C':
                return 100;
                break;
            case 'D':
                return 500;
                break;
            case 'M':
                return 1000;
                break;
            default:
                return 0;
                break;
            }
        };
        char LC='I';
        for(auto i=s.rbegin();i!=s.rend();i++){
            if(hashlist(*i)<hashlist(LC))
                result -= hashlist(*i);
            else
                result += hashlist(*i);
            LC=*i;
        }
        return result;
    }
};

class Solution1 {
public:
    int romanToInt(string s) {
        int ans = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            switch (s[i]) {
            case 'I':
                if (s[i + 1] == 'V') {
                    i++;
                    ans += 4;
                }
                else if (s[i + 1] == 'X') {
                    i++;
                    ans += 9;
                }
                else
                    ans += 1;
                break;
            case 'V':
                ans += 5;
                break;
            case 'X':
                if (s[i + 1] == 'L') {
                    i++;
                    ans += 40;
                }
                else if (s[i + 1] == 'C') {
                    i++;
                    ans += 90;
                }
                else
                    ans += 10;
                break;
            case 'L':
                ans += 50;
                break;
            case 'C':
                if (s[i + 1] == 'D') {
                    i++;
                    ans += 400;
                }
                else if (s[i + 1] == 'M') {
                    i++;
                    ans += 900;
                }
                else
                    ans += 100;
                break;
            case 'D':
                ans += 500;
                break;
            default:
                ans += 1000;
                break;
            }
        }
        return ans;
    }
};

int main()
{
    Solution S;
    cout<<S.romanToInt("CMLXXXVII");
}