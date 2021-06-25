#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <regex>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1); //0,1,1,2,1,2
        res[0] = 0;
        for (int i = 1; i < num + 1; i++)
        {
            if (i % 2 == 1)
                res[i] = res[i-1] + 1;
            else
                res[i] = res[i>>1];
        }
        return res;
    }
};