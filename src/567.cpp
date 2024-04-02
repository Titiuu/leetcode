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
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for (auto c : s1)
            need[c]++;
        int left = 0, right = 0;
        while (right < s2.size()) {
            window[s2[right]]++;
            right++;
            while (right - left > s1.size()) {
                if (cover(window, need))
                    return true;
                window[s2[left]]--;
                left++;
            }
        }
        return false;
    }
};

int main() {
    string s1 = "ab", s2 = "eidbaooo";
    Solution s;
    s.checkInclusion(s1, s2);
}