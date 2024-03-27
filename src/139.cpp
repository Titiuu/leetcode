#include "head.h"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto wordDictSet = unordered_set <string> (wordDict.begin(), wordDict.end());
        int longestLen = 0;
        for (auto x : wordDictSet) {
            longestLen = max(longestLen, (int)x.size());
        }
        auto dp = vector <bool>(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && i - j <= longestLen && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

//***************************************************************************
class Solution { // 超时
public:
    int flag = 0;
    bool comp(string& s, string& temp, int start) {
        for (int i = start; i < temp.size(); i++) {
            if (s[i] != temp[i])
                return false;
        }
        return true;
    }
    void backtrace(string& s, vector<string>& wordDict, string& temp, int start) { // start表示比较的起点
        if (flag == 1)
            return;
        if (temp.size() == s.size() && comp(s, temp, start)) {
            flag = 1;
            return;
        }
        if (temp.size() > s.size())
            return;
        if (!comp(s, temp, start))
            return;
        for (int i = 0; i < wordDict.size(); i++) {
            int n = wordDict[i].size();
            temp = temp + wordDict[i];
            backtrace(s, wordDict, temp, temp.size() - n);
            for (int j = 0; j < n; j++)
                temp.pop_back();
        }
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        string temp;
        backtrace(s, wordDict, temp, 0);
        return flag == 1;
    }
};

//************************************************************************

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto wordDictSet = unordered_set <string> (wordDict.begin(), wordDict.end());
        int longestLen = 0, shortestLen = 1e8;
        for (auto x : wordDictSet) {
            longestLen = max(longestLen, (int)x.size());
            shortestLen = min(shortestLen, (int)x.size());
        }
        auto dp = vector <bool>(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = max( 0 ,i - longestLen) ; j <= i - shortestLen; ++j) {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};