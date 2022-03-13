# include "head.h"

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cnt = 0;
        for (int x: data) {
            if (cnt != 0) {
                if ((x & 0xC0) == 0x80) {
                    cnt--;
                } else {
                    return false;
                }
            } else if ((x & 0xE0) == 0xC0) {
                cnt = 1;
            } else if ((x & 0xF0) == 0xE0) {
                cnt = 2;
            } else if ((x & 0xF8) == 0xF0) {
                cnt = 3;
            } else if ((x & 0x80) != 0) {
                return false;
            }
        }
        return cnt == 0;
    }
};