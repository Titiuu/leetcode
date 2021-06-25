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

using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if (n == 0) return false;
        while(n % 5 == 0)
            n /= 5;
        while(n % 3 == 0)
            n /= 3;
        while(n % 2 == 0)
            n /= 2;
        if (n == 1) return true;
        return false;
    }
};