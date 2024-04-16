#include "head.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        string charset;
        //size_t index=0;
        int maxSize = 1;
        for (size_t i = 0; i < s.size(); i++)
        {
            for (size_t j = i; j < s.size(); j++)
            {
                if(charset.find(s[j])==charset.npos){
                    charset.push_back(s[j]);
                }
                else{
                    if(maxSize < charset.size())
                        maxSize = charset.size();
                    i = i + charset.find(s[j]);
                    charset.clear();
                    break;
                }
            }
        }
        return maxSize;
    }
};

class Solution6 {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1)
            return s.size();
        int left = 0, right = 1, res = 0;
        while (right <= s.size()) {
            string subs = s.substr(left, right - left);
            auto set = unordered_set<char> {};
            for (auto& c : subs)
                set.insert(c);
            if (right - left == set.size()) {
                res = max(res, right - left);
                right++;
            }
            else
                left++;
        }
        return res;
    }
};

class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1)
            return s.size();
        int left = 0, right = 1, res = 0;
        string subs = s.substr(left, right - left);
        auto set = unordered_set<char> {s[0]};
        while (right < s.size()) {
            while (right < s.size() && set.count(s[right]) == 0) {
                set.insert(s[right]);
                right++;
            }
            res = max(res, right - left);
            set.erase(s[left]);
            left++;
        }
        return res;
    }
};

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1)
            return s.size();
        int left = 0, right = 0, res = 0;
        unordered_map<char,int> mp;
        while (right < s.size()) {
            mp[s[right]]++;
            right++;
            while(mp[s[right-1]] > 1){
                mp[s[left]]--;
                left++;
            }
            res = max(res, right - left);
        }
        return res;
    }
};


int main()
{
    Solution2 S;
    string s="aab";
    cout<<S.lengthOfLongestSubstring(s);
}