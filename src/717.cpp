#include "head.h"

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int count = 0;
        for (int i = bits.size() - 2; i > -1; i--) {
            if (bits[i] == 1)
                count++;
            else
                break;
        }
        if (count % 2 == 0) return true;
        return false;
    }
}; 