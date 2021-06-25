#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        string s = to_string(x);
        int i=0, j=s.size()-1;
        while(i<=j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};

class Solution1 {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int rev=0, temp=x;
        while(temp!=0){
            rev*=10;//溢出
            rev+=temp%10;
            temp/=10;
        }
        if (rev==x) return true;
        return false;
    }
};

int main()
{
    Solution S;
    cout << S.isPalindrome(1551);
}