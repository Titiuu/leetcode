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
#include <set>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) {
            return 0;
        }
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (divisor == 1)
            return dividend;
        if (divisor == -1)
            return -dividend;
        int count = 0;
        unsigned a = abs(dividend), b = abs(divisor); //a为被除数，b为除数
        while (a >= b) {
            a -= b;
            count++;
        }
        return (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0) ? count : -count;
    }
};