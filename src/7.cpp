#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>

using namespace std;

// class Solution {
// public://不好
//     int reverse(int x) {
//         string s = to_string(x), str;
//         str.assign(s.rbegin(),s.rend());
//         int intStr = atoi(str.c_str());
//         if(x<0) return 0-intStr;
//         return intStr;
//     }
// };

class Solution1 {
public:
    int reverse(int x) {
        int rev = 0;    
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

int main()
{
    Solution1 S1;
    cout << S1.reverse(1534236469);
}