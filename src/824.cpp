#include "head.h"

class Solution {
public:
    const unordered_set<char> vowel = { 'a', 'e', 'i', 'o', 'u' ,'A','E','I','O','U' };
    string toGoatLatin(string sentence) {
        vector<string> words;
        string temp;
        for (auto c : sentence) {
            if (c != ' ') {
                temp.push_back(c);
            }
            else {
                words.push_back(temp);
                temp.clear();
            }
        }
        words.push_back(temp);
        int n = words.size();
        for (int i = 0; i < n; i++) {
            if (vowel.count(words[i][0]) == 0) {
                char c = words[i][0];
                words[i].erase(0,1);
                words[i].push_back(c);
                words[i].append("ma");
            }
            else {
                words[i].append("ma");
            }
            for (int j = 0; j < i + 1; j++) {
                words[i].push_back('a');
            }
        }
        string res;
        for (auto word : words) {
            res.append(word);
            res.push_back(' ');
        }
        res.pop_back();
        return res;
    }
};

int main() {
    Solution S;
    S.toGoatLatin("I speak Goat Latin");
    return 0;
}