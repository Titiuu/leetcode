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
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            if (n & 1) {
                res++;
            }
            n >>= 1;
        }
        return res;
    }
};

int main() {
    Solution S;
    cout<<S.hammingWeight(0b00000000000000000000000000001011);
}