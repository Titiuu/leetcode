#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int toint = 0;
        int i = 0;
        while(s[i]==' '){
            if(i==s.size()-1)  break;
            i++;
        }
        if((s[i]<0x30 || s[i]>0x39) && s[i]!='-' && s[i]!='+')
            return 0;
        if(s[i]=='-'){
            i++;
            int j=i;
            while(0x2F<s[j] && s[j]<0x3A){
                if (toint > INT_MAX/10 || (toint == INT_MAX / 10 && s[j] > 0x37)) return -INT_MAX-1;
                toint *= 10;
                toint += s[j] - 0x30;
                if(j==s.size()-1)  break;
                j++;
            }
            return 0-toint;
        }
        else if(s[i]=='+'){
            i++;
        }
        int j = i;
        while (0x2F < s[j] && s[j] < 0x3A)
        {
            if (toint > INT_MAX / 10 || (toint == INT_MAX / 10 && s[j] > 0x37))
                return INT_MAX;
            toint *= 10;
            toint += s[j] - 0x30;
            if (j == s.size() - 1)
                break;
            j++;
        }
        return toint;
    }
};

int main()
{
    Solution S;
    cout << S.myAtoi("-91283472332");
}