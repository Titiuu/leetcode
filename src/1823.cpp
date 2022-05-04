#include "head.h"

class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 1;
        for (int i = 2; i <= n; i++) {
            winner = (k + winner - 1) % i + 1;
        }
        return winner;
    }
};