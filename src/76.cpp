#include "head.h"

class Solution {
private:
    bool cover(unordered_map<char, int>& a, unordered_map<char, int>& b) {
        // if a cover b return true else false
        for (auto& x : b) {
            if (a[x.first] < x.second)
                return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> window, need;
        for (auto c : t)
            need[c]++;
        int left = 0, right = 0;
        int len = INT_MAX, start = -1; //记录当前覆盖子串 长度 和 起始位置
        while (right < s.size()) {
            char c = s[right];
            if (need.count(c)) { //需要往window里面加入
                window[c]++;
            }
            right++;
            //当window里的每个key-value都覆盖了need就要缩小窗口
            while (left < right && cover(window, need)) {
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                char d = s[left];
                if (need.count(d)) { //需要从window里删去
                    window[d]--;
                }
                left++;
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> window, need;
        for (auto c : t)
            need[c]++;
        int left = 0, right = 0;
        int len = INT_MAX, start = -1; //记录当前覆盖子串 长度 和 起始位置
        int valid = 0;
        while (right < s.size()) {
            char c = s[right];
            if (need.count(c)) { //需要往window里面加入
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }
            right++;
            //当window里的每个key-value都覆盖了need就要缩小窗口
            while (left < right && valid == need.size()) {
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                char d = s[left];
                if (need.count(d)) { //需要从window里删去
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
                left++;
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};