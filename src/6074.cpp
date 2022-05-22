#include "head.h"

class Solution {
public:
    int percentageLetter(string s, char letter) {
        double n = s.size(), count = 0;
        for (auto& c : s) {
            if (c == letter) {
                count += 1;
            }
        }
        return floor(count / n * 100);
    }
};