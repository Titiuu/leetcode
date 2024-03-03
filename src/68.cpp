#include "head.h"

class Solution {
private:
    string getLine(vector<string>& words, int start, int end, int maxWidth) {
        string s;
        if (end == words.size() - 1) {
            for (int i = start; i < end; i++) {
                s += words[i] + ' ';
            }
            s += words[end];
            while (s.size() < maxWidth)
                s += ' ';
        }
        else if (end == start) {
            s += words[start];
            while (s.size() < maxWidth)
                s += ' ';
        }
        else {
            int num = end - start; // 单词之间的空的数量
            int wordsLen = 0;
            for (int i = start; i <= end; i++) {
                wordsLen += words[i].size();
            }
            int spaceNum = maxWidth - wordsLen; // 应该添加的空格数量
            int spaces = spaceNum / num, numOfPlusOneSp = spaceNum % num; // 基础空格数量、前几个空需要额外添加一个空格
            for (int i = start; i < end; i++) {
                s += words[i];
                int plusOne = i - start + 1 > numOfPlusOneSp ? spaces : spaces + 1;
                for (int j = 0; j < plusOne; j++) {
                    s += ' ';
                }
            }
            s += words[end];
        }
        return s;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> res;
        int len = 0, start_index = 0;
        for (int i = 0; i < n; i++) {
            if (len == 0)
                start_index = i; // 说明是新的一行
            len += words[i].size() + 1;
            if (len > maxWidth + 1) { // 说明最后一个单词不应该加
                len -= words[i].size() + 1;
                i--;
                res.push_back(getLine(words, start_index, i, maxWidth));
                len = 0;
            }
            else if (i == n - 1 || len == maxWidth + 1) {
                res.push_back(getLine(words, start_index, i, maxWidth));
                len = 0;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> words = { "ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country" };
    vector<string> res = s.fullJustify(words, 16);
    return 0;
}