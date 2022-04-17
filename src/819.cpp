#include "head.h"

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        vector<string> words;
        string word;
        for (auto c : paragraph) {
            if (c >= 'a' && c <= 'z') {
                word.push_back(c);
            }
            else if (c >= 'A' && c <= 'Z') {
                word.push_back(c - 'A' + 'a');
            }
            else {
                if (!word.empty())
                    words.emplace_back(word);
                word.clear();
            }
        }
        if(!word.empty())
            words.emplace_back(word);
        unordered_map<string, int> hashmap;
        int res = 0;
        string ret;
        for (auto word : words) {
            int flag = 0;
            for (auto ban : banned) {
                if (ban == word) {
                    flag = 1;
                }
            }
            if (flag == 0) {
                if (hashmap.count(word) == 0) {
                    hashmap[word] = 1;
                }
                else {
                    hashmap[word]++;
                }
                if (hashmap[word] > res) {
                    res = hashmap[word];
                    ret = word;
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution S;
    vector<string> banned = { "hit","bob"};
    cout << S.mostCommonWord("Bob. hIt, baLl", banned);
    return 0;
}