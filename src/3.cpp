#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        string charset;
        //size_t index=0;
        int maxSize = 1;
        for (size_t i = 0; i < s.size(); i++)
        {
            for (size_t j = i; j < s.size(); j++)
            {
                if(charset.find(s[j])==charset.npos){
                    charset.push_back(s[j]);
                }
                else{
                    if(maxSize < charset.size())
                        maxSize = charset.size();
                    i = i + charset.find(s[j]);
                    charset.clear();
                    break;
                }
            }
        }
        return maxSize;
    }
};

int main()
{
    Solution S;
    string s="aab";
    cout<<S.lengthOfLongestSubstring(s);
}