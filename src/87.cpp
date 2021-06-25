#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <regex>
#include <cmath>
#include <numeric>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        // 长度不等，必定不能变换
        if (s1.length() != s2.length()) {
            return false;
        }
        // 长度相等，先特判下
        if (s1==s2) {
            return true;
        }
        // 看一下字符个数是否一致，不同直接return false
        int n = s1.length();
        unordered_map<char, int> hash;
        for (int i = 0; i < n; i++) {
            char c1 = s1[i];
            char c2 = s2[i];
            if (hash.find(c1)==hash.end())
                hash[c1] = 1;
            else
                hash[c1]++;
            if (hash.find(c2)==hash.end())
                hash[c2] = -1;
            else
                hash[c2]--;
        }
        for (pair pairs : hash) {
            if (pairs.second != 0) {
                return false;
            }
        }
        // 相同的话，开始判断判断，满足一个就能 return true
        for (int i = 1; i < n; i++) {
            bool flag =
                    // S1 -> T1，S2 -> T2
                    (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n - i), s2.substr(i, n-i))) ||
                    // S1 -> T2，S2 -> T1
                    (isScramble(s1.substr(0, i), s2.substr(n - i, i)) && isScramble(s1.substr(i, n - i), s2.substr(0, n - i)));
            if (flag) {
                return true;
            }
        }
        return false;
    }
};


//official answer
class Solution1 {
private:
    // 记忆化搜索存储状态的数组
    // -1 表示 false，1 表示 true，0 表示未计算
    int memo[30][30][31];
    string s1, s2;

public:
    bool checkIfSimilar(int i1, int i2, int length) {
        unordered_map<int, int> freq;
        for (int i = i1; i < i1 + length; ++i) {
            ++freq[s1[i]];
        }
        for (int i = i2; i < i2 + length; ++i) {
            --freq[s2[i]];
        }
        if (any_of(freq.begin(), freq.end(), [](const auto& entry) {return entry.second != 0;})) {
            return false;
        }
        return true;
    }

    // 第一个字符串从 i1 开始，第二个字符串从 i2 开始，子串的长度为 length，是否和谐
    bool dfs(int i1, int i2, int length) {
        if (memo[i1][i2][length]) {
            return memo[i1][i2][length] == 1;
        }

        // 判断两个子串是否相等
        if (s1.substr(i1, length) == s2.substr(i2, length)) {
            memo[i1][i2][length] = 1;
            return true;
        }

        // 判断是否存在字符 c 在两个子串中出现的次数不同
        if (!checkIfSimilar(i1, i2, length)) {
            memo[i1][i2][length] = -1;
            return false;
        }
        
        // 枚举分割位置
        for (int i = 1; i < length; ++i) {
            // 不交换的情况
            if (dfs(i1, i2, i) && dfs(i1 + i, i2 + i, length - i)) {
                memo[i1][i2][length] = 1;
                return true;
            }
            // 交换的情况
            if (dfs(i1, i2 + length - i, i) && dfs(i1 + i, i2, length - i)) {
                memo[i1][i2][length] = 1;
                return true;
            }
        }

        memo[i1][i2][length] = -1;
        return false;
    }

    bool isScramble(string s1, string s2) {
        memset(memo, 0, sizeof(memo));
        this->s1 = s1;
        this->s2 = s2;
        return dfs(0, 0, s1.size());
    }
};

