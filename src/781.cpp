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
    int numRabbits(vector<int>& answers) {
        if (answers.empty())    return 0;
        map<int,int> hash;
        for (int i = 0; i < answers.size(); i++)
        {
            int n = answers[i];
            if (hash.find(n) != hash.end())
                hash[n] += 1;
            else
                hash[n] = 1;
        }
        int res = 0;
        for (auto i:hash) {
            res += ceil(i.second / (i.first + 1.0)) * (i.first + 1);
        }
        return res;
    }
};