#include "head.h"

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(), [](string a, string b) {
            return a.size() < b.size();
            });
        int len = words.size();
        vector<string> res;
        for (int i = 0; i < len - 1; i++) {
            string pat = words[i];
            for (int j = i + 1; j < len; j++) {
                if (words[j].find(pat) != string::npos) {
                    res.emplace_back(pat);
                    break;
                }
            }
        }
        return res;
    }
};