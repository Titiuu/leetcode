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

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.length();
        int i = 0;
        int slots = 1;
        while (i < n) {
            if (slots == 0)
                return false;
            switch (preorder[i])
            {
            case ',':
                i++;
                break;
            case '#':
                slots--;
                i++;
                break;
            default:
                i += 2;
                slots++;
                break;
            }
        }
        return slots == 0;
    }
};