#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string str; //"IVXLCDM" 1,5,10,50,100,500,1000
        int t = num / 1000, h = (num/100) % 10, d = (num/10) % 10, s = num % 10;
        switch (t)
        {//1000
        case 3:
            str += "MMM";
            break;
        case 2:
            str += "MM";
            break;
        case 1:
            str += "M";
            break;
        default:
            break;
        }
        switch (h)
        {//100
        case 9:
            str += "CM";
            break;
        case 8:
            str += "DCCC";
            break;
        case 7:
            str += "DCC";
            break;
        case 6:
            str += "DC";
            break;
        case 5:
            str += "D";
            break;
        case 4:
            str += "CD";
            break;
        case 3:
            str += "CCC";
            break;
        case 2:
            str += "CC";
            break;
        case 1:
            str += "C";
            break;
        default:
            break;
        }
        switch (d)
        {//10
        case 9:
            str += "XC";
            break;
        case 8:
            str += "LXXX";
            break;
        case 7:
            str += "LXX";
            break;
        case 6:
            str += "LX";
            break;
        case 5:
            str += "L";
            break;
        case 4:
            str += "XL";
            break;
        case 3:
            str += "XXX";
            break;
        case 2:
            str += "XX";
            break;
        case 1:
            str += "X";
            break;
        default:
            break;
        }
        switch (s)
        {//1
        case 9:
            str += "IX";
            break;
        case 8:
            str += "VIII";
            break;
        case 7:
            str += "VII";
            break;
        case 6:
            str += "VI";
            break;
        case 5:
            str += "V";
            break;
        case 4:
            str += "IV";
            break;
        case 3:
            str += "III";
            break;
        case 2:
            str += "II";
            break;
        case 1:
            str += "I";
            break;
        default:
            break;
        }
        return str;
    }
};

int main()
{
    Solution S;
    cout<<S.intToRoman(987);
}