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

class Solution1 {
public:
    string convert(string s, int numRows) {
        vector<string> Rows(numRows, "");
        int n = s.size();
        int flag = 0;
        for (int i = 0; i < n; i++) {
            if (flag == 0) {
                for (int j = 0; j < numRows; j++) {
                    Rows[j] += s[i];
                    i++;
                    if (i == n)
                        break;
                }
                flag = 1;
                i--;
            }
            else {
                for (int j = 0; j < numRows - 2; j++) {
                    Rows[numRows - 2 - j] += s[i];
                    i++;
                    if (i == n)
                        break;
                }
                flag = 0;
                i--;
            }
        }
        string ans = "";
        for (auto& s : Rows)
            ans += s;
        return ans;
    }
};

int main()
{
    Solution1 S;
    cout<<S.convert("PAYPALISHIRING",4);
}