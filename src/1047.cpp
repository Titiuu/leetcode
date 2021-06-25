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
    string isPalindrome(string s, int blank) {
        if(s.size()<3)  return "";
        int i;
        for (i = 0; blank - i >= 0 && blank + i + 1 < s.size(); i++)
        {
            if(s[blank-i] != s[blank+i+1])
                return s.substr(blank-i+1, 2*i);
        }
        i--;
        return s.substr(blank-i, 2*i+2);
    }
    string Palindrome(string s) {
        if(s.size()==0) return "";
        if(s.size()==1) return "";
        if(s.size()==2){
            if(s[0]==s[1]) return s;
            else
                return "";
        }
        string temp;
        for (int i = 0; i < s.size()-1; i++)
            if(isPalindrome(s,i).size() != 0) {
                temp = isPalindrome(s,i);
                break;
            }
        return temp;
    }
    string removeDuplicates(string S) {
        string temp;
        while ((temp = Palindrome(S)).size()!=0) {
            int pos = 0;
            while (string::npos != (pos = S.find(temp)))
            {
                S.erase(pos, temp.size());
            }
        }
        return S;
    } //time limited
    string removeDuplicates1(string S) {
        for (int i=0; i < S.size(); i++) {
            if (S[i]==S[i+1]) {
                S.erase(i,2);
                if (i!=0)
                    i-=2;
                else
                    i--;
            }
        }
        return S;
    }
};

int main() {
    Solution S;
    cout<<S.removeDuplicates1("abbaca");
}