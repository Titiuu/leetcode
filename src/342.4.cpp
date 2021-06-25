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
    bool isPowerOfFour(int n) {
        if (n > 0 && ((n & (n-1)) == 0)) {
            int count = 0;
            while (n != 1) {
                n >>= 1;
                count++;
            }
            if (count % 2 == 0)
                return true;
        }
        return false;
    }
};