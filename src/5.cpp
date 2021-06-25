#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() <= 2 && s[0]==s[s.size()-1])
            return true;
        if (s[0] != s[s.size()-1])
            return false;
        else
            return isPalindrome(s.substr(1,s.size()-2));
    }
    string longestPalindrome(string s) {
        if(s.size()==1) return s;
        if(s.size()==2){
            if(s[0]==s[1]) return s;
            else
                return s.substr(0,1);
        }
        for (size_t length = s.size(); length > 0; length--)
        {
            for (size_t i = 0; i < s.size() - length + 1; i++)
            {
                if (isPalindrome(s.substr(i, length)))
                    return s.substr(i, length);
            }         
        }  // time limit
        return "";
    }
};

class Solution1 {
public:
    string isLongerPalindrome1(string s, int index) {
        if(s.size()<3)  return "";
        int i;
        for (i = 1; index - i >= 0 && index + i < s.size(); i++)
        {
            if(s[index-i] != s[index+i])
                return s.substr(index-i+1, 2*i-1);
        }
        i--;
        return s.substr(index-i, 2*i+1);
    }
    string isLongerPalindrome2(string s, int blank) {
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
    string longestPalindrome(string s) {
        if(s.size()==0) return "";
        if(s.size()==1) return s;
        if(s.size()==2){
            if(s[0]==s[1]) return s;
            else
                return s.substr(0,1);
        }
        string temp;
        for (int i = 1; i < s.size()-1; i++)
            if(isLongerPalindrome1(s,i).size()>temp.size())
                temp = isLongerPalindrome1(s,i);
        for (int i = 0; i < s.size()-1; i++)
            if(isLongerPalindrome2(s,i).size()>temp.size())
                temp = isLongerPalindrome2(s,i);
        return temp;
    }
};

int main()
{
    Solution1 S;
    //cout<<S.longestPalindrome("miycvxmqggnmmcwlmizfojwrurwhwygwfykyefxbgveixykdebenzitqnciigfjgrzzbtgeazyrbiirmejhdwcgjzwqolrturjlqpsgunuqerqjevbheblmbvgxyedxshswsokbhzapfuojgyfhctlaifrisgzqlczageirnukgnmnbwogknyyuynwsuwbumdmoqwxprykmazghcpmkdcjduepjmjdxrhvixxbfvhybjdpvwjbarmbqypsylgtzyuiqkexgvirzylydrhrmuwpmfkvqllqvekyojoacvyrzjevaupypfrdguhukzuqojolvycgpjaendfetkgtojepelhcltorueawwjpltehbbjrvznxhahtuaeuairvuklctuhcyzomwrrznrcqmovanxmiyilefybkbveesrxkmqrqkowyrimuejqtikcjfhizsmumajbqglxrvevexnleflocxoqgoyrzgqflwiknntdcykuvdcpzlakljidclhkllftxpinpvbngtexngdtntunzgahuvfnqjedcafzouopiixw");
    cout<<S.longestPalindrome("acaacb");
}