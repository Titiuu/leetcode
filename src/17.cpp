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

class Solution1 {
public:
    vector<vector<char>> letters { {'a','b','c'}, {'d','e','f'}, {'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'} };
    vector<string> res;
    void backtrack(string digits, int start, string& track) {
        if (start == digits.size()) {
            res.emplace_back(track);
            return;
        }
        for (int j = 0; j < letters[digits[start] - '2'].size(); j++) {
            track.push_back(letters[digits[start] - '2'][j]); //做出选择
            backtrack(digits, start + 1, track); //回溯
            track.pop_back(); //撤销选择
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits == "")
            return {};
        string track;
        backtrack(digits, 0, track);
        return res;
    }
};

int main()
{
    Solution1 S;
    vector<string> re;
    re = S.letterCombinations("3");
    for(auto i:re){
        cout<<i<<"  ";
    }
}