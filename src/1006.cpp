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
    int clumsy(int N) {
        if (N < 4) {
            switch (N)
            {
            case 3:
                return 6;
                break;
            case 2:
                return 2;
            case 1:
                return 1;
            default:
                break;
            }
        }
        int res = 0;
        int left = N % 4, times = N / 4;
        int n1 = left + 1, n2 = left + 2, n3 = left + 3, n4 = left + 4;
        for (int i = 0; i < times - 1; i++) {
            res += -n4 * n3 / n2 + n1;
            n1 += 4;
            n2 += 4;
            n3 += 4;
            n4 += 4;
        }
        res += n4 * n3 / n2 + n1;
        switch (left)
        {
        case 3:
            res += -3 * 2 / 1;
            break;
        case 2:
            res += -2 * 1;
            break;
        case 1:
            res += -1;
            break;
        default:
            break;
        }
        return res;
    }
};