#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> rows(min(numRows, int(s.size())));

        for (size_t i = 0; i < s.size(); i++)
        {
            if((i/(numRows-1)) % 2 == 0)
                rows[i%(numRows-1)] += s[i];
            else
                rows[numRows-1-i%(numRows-1)] += s[i];
        }
        string Rs;
        for (size_t i = 0; i < rows.size(); i++)
            Rs += rows[i];
        return Rs;
    }
};

int main()
{
    Solution S;
    cout<<S.convert("PAYPALISHIRING",4);
}