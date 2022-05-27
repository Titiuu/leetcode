#include "head.h"

class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int n = words.size();
        int index1 = -1, index2 = -1;
        int res = 9999999;
        for (int i = 0; i < n; i++) {
            if (words[i] == word1) {
                index1 = i;
                if (index2 != -1) {
                    res = min(index1 - index2, res);
                }
            }
            if (words[i] == word2) {
                index2 = i;
                if (index1 != -1) {
                    res = min(index2 - index1, res);
                }
            }
        }
        return res;
    }
};