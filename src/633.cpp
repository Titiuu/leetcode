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
    bool judgeSquareSum(int c) {
        for (int i = 1; i <= (int)pow(c/2, 0.5)+1; i++) {
            double p = pow(c-i*i, 0.5);
            if (floor(p)==ceil(p))
                return true;
        }
        return false;
    }
};