#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <regex>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> re;
        if (digits.size()==0)   return re;
        // map<int, string> hash={
        //     {2,"abc"},
        //     {3,"def"},
        //     {4,"ghi"},
        //     {5,"jkl"},
        //     {6,"mno"},
        //     {7,"pqrs"},
        //     {8,"tuv"},
        //     {9,"wxyz"}
        // };

        auto hash = [](char c){
            switch (c)
            {
            case '2':
                return "abc";
                break;
            case '3':
                return "def";
                break;
            case '4':
                return "ghi";
                break;
            case '5':
                return "jkl";
                break;
            case '6':
                return "mno";
                break;
            case '7':
                return "pqrs";
                break;
            case '8':
                return "tuv";
                break;
            case '9':
                return "wxyz";
                break;             
            default:
                return "";
                break;
            }
        };

        string temp = hash(digits[0]);
        for (size_t i = 0; i < temp.size(); i++){
            string s(1,temp[i]);
            re.push_back(s);
        }
        for (size_t i = 1; i < digits.size(); i++)
        {
            vector<string> copy = re, copy1 = re;
            re.clear();
            string temp = hash(digits[i]);
            for (size_t j = 0; j < temp.size(); j++)
            {
                for (size_t k = 0; k < copy.size(); k++)
                {
                    copy[k].push_back(temp[j]);
                }
                re.insert(re.end(), copy.begin(), copy.end());
                copy = copy1;
            }
        }
        return re;
    }
};

int main()
{
    Solution S;
    vector<string> re;
    re = S.letterCombinations("23");
    for(auto i:re){
        cout<<i<<"  ";
    }
}