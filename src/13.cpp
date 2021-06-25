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

int main()
{
    Solution S;
    cout<<S.romanToInt("CMLXXXVII");
}