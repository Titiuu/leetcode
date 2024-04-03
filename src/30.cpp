#include "head.h"

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.size() == 0)//判断words为空,因为下面用到了words[0]
            return {};
        vector<int> ret;
        int word_size = words[0].size();
        int word_num = words.size();
        
        unordered_map<string,int> m1;//构造hashmap
        for (int i = 0;i < word_num;i++)
            m1[words[i]]++;
        
        unordered_map<string,int> m2;
        for(int i=0; (i + word_size * word_num) <= s.size() ; i++){//截取的s符合题意
            int j = 0;
            for(j=i;j < (i + word_size * word_num) ; j=j+word_size){//分段判断
                string temp_str = s.substr(j,word_size);
                if(m1[temp_str] == 0){//m1中没有截取的串，直接跳出
                    break;
                }else{
                    m2[temp_str]++;
                    if(m1[temp_str] < m2[temp_str])//重复次数过多，也跳出
                        break;
                }
            }
            
            if(j == (i + word_size * word_num))//每一段都符合，则加入答案
                ret.push_back(i);
            
            m2.clear();//清空m2
        }
        return ret;
    }
};

class Solution1 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> need, window;
        int len = words[0].size();
        for (auto& x : words)
            need[x]++;
        int left = 0, right = 0; // [)
        int count = 0; // 对window中符合了的计数
        vector<int> res;
        while (right < s.size()) {
            string s1 = s.substr(right, len);
            if (need.count(s1) != 0) { //说明需要直接right右移len
                window[s1]++;
                if (window[s1] == need[s1])
                    count++;
                right += len;
            }
            else { // 说明不符合了，直接清空window right++
                window.clear();
                right++;
            }
            while (left < right && count == need.size()) {
                string s2 = s.substr(left, len);
                if (right - left == len * words.size()) {
                    res.push_back(left);
                }
                if (need.count(s2) != 0) {
                    if (window[s2] == need[s2])
                        count--;
                    window[s2]--;
                    left += len;
                }
                else
                    left++;
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> need, window;
        int len = words[0].size();
        for (auto& x : words)
            need[x]++;
        int left = 0, right = 0; // [)
        int count = 0; // 对window中符合了的计数
        vector<int> res;
        while (right < s.size()) {
            right++;
            while (right - left == len * words.size()) {
                for (int i = 0; i < right; i += len) {
                    string s1 = s.substr(left + i, len);
                    if (need.count(s1) == 0) {
                        break;
                    }
                    else {
                        window[s1]++;
                        if (window[s1] == need[s1])
                            count++;
                        else if (window[s1] > need[s1]) {
                            break;
                        }
                    }
                }
                if (count == need.size()) {
                    res.push_back(left);
                }
                count = 0;
                window.clear();
                left++;
            }
        }
        return res;
    }
};

class Solution3 {
private:
    bool isValid(unordered_map<string, int>& a, unordered_map<string, int>& b) {
        for (auto [first, second] : b) {
            if (a[first] != second)
                return false;
        }
        return true;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> need;
        int len = words[0].size();
        for (auto& x : words)
            need[x]++;
        vector<int> res;
        // 使用dp记录固定长度子串情况
        if (s.size() < words.size() * len)
            return {};
        vector<unordered_map<string, int>> dp(s.size() - len * words.size() + 1, unordered_map<string, int>());
        for (int i = 0; i < len && i <= s.size() - len * words.size(); i++) {
            for (int j = i; j < i + len * words.size(); j+=len) {
                string s1 = s.substr(j, len);
                if (need.count(s1) != 0) {
                    dp[i][s1]++;
                }
            }
            if (isValid(dp[i], need)) {
                res.push_back(i);
            }
        }
        for (int i = len; i <= s.size() - len * words.size(); i++) {
            dp[i] = dp[i - len];
            string front = s.substr(i - len, len), back = s.substr(i + len * (words.size() - 1), len);
            if (need.count(front) != 0)
                dp[i][front]--;
            if (need.count(back) != 0)
                dp[i][back]++;
            if (isValid(dp[i], need)) {
                res.push_back(i);
            }
        }
        
        return res;
    }
};


int main() {
    vector<string> words { {"ababa"},{"babab"} };
    string s = "ababababab";
    Solution3 sl;
    sl.findSubstring(s, words);
}