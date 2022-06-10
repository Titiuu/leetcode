#include "head.h"

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int res = 0, flag = 0;
        text.push_back(' ');
        for (int i = 0; i < text.size(); i++) {
            if (flag == 0) {
                if (text[i] == ' ') {
                    res++;
                    continue;
                }
                if (brokenLetters.find(text[i]) != brokenLetters.npos) {
                    flag = 1;
                }
            }
            if (flag == 1) {
                if (text[i] == ' ') {
                    flag = 0;
                    continue;
                }
                if (brokenLetters.find(text[i]) != brokenLetters.npos) {
                    flag = 1;
                }
            }
        }
        return res;
    }
};