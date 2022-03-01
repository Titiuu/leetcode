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