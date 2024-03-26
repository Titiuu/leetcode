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
    vector<string> generateParenthesis(int n)
    {//动态规划
        if (n == 0)
            return {};
        if (n == 1)
            return {"()"};
        if (n == 2)
            return {"(())", "()()"};
        if (n == 3)
            return {"((()))", "(()())", "(())()", "()(())", "()()()"};
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};
        dp[1] = {"()"};
        dp[2] = {"(())", "()()"};
        dp[3] = {"((()))", "(()())", "(())()", "()(())", "()()()"};
        for (int i = 4; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                for (string p : dp[j])
                    for (string q : dp[i - j - 1])
                    {
                        string str = "(" + p + ")" + q;
                        dp[i].push_back(str);
                    }
            }
        }
        return dp[n];
    }
    // vector<string> generateParenthesis(int n) {
    //     vector<string> res = {"()"};
    //     if (n==1) return res;
    //     auto getIndex = [](string s) {
    //         vector<int> indexlist;
    //         int index = -2;
    //         while ((index = s.find("()", index + 2)) != string::npos)
    //             indexlist.push_back(index);
    //         return indexlist;
    //     };
    //     for (int i = 1; i < n; i++)
    //     {
    //         vector<string> temp;
    //         for(auto j:res)
    //         {
    //             vector<int> indexs;
    //             indexs = getIndex(j);
    //             int record = -3;
    //             for (size_t k = 0; k < indexs.size(); k++)
    //             {
    //                 int index_k = indexs[k];
    //                 string dummy = j;
    //                 dummy.insert(index_k,"()");
    //                 temp.push_back(dummy);
    //                 dummy = j;
    //                 if (index_k != record + 2) {
    //                     dummy.insert(index_k + 1,"()");
    //                     temp.push_back(dummy);
    //                 }
    //                 record = index_k;
    //             }
    //         }
    //         res = temp;
    //     }
    //     return res;
    // }
};
//******************************************************
class Solution1 {
private:
    bool moreRight(string track, bool front) {
        int l = 0, r = 0;
        if (front)
            track.pop_back();
        for (auto& x : track) {
            if (x == '(')
                l++;
            else
                r++;
        }
        return r >= l;
    }
public:
    vector<string> res;
    int num;
    vector<char> b;
    void backtrack(int start, string& track) {
        if (!track.empty() && track.back()==')' && moreRight(track, true)) {
            return;
        }
        if (start == num * 2) {
            if (moreRight(track, false))
                res.emplace_back(track);
            return;
        }
        for (int i = 0; i < 2; i++) {
            track.push_back(b[i]); //做出选择
            backtrack(start + 1, track); //回溯
            track.pop_back(); //撤销选择
        }
    }
    vector<string> generateParenthesis(int n) {
        num = n;
        b = { '(', ')' };
        string s;
        backtrack(0, s);
        return res;
    }
};

int main() {
    Solution1 S;
    vector<string> box;
    box = S.generateParenthesis(2);
    for (auto i:box)
    {
        cout<<i<<"  ";
    }
}