#include "head.h"

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int num1 = 0, num2 = 0;
        for (auto& x : bills) {
            if (x == 5) {
                num1++;
            }
            else if (x == 10) {
                num1--;
                num2++;
            }
            else {
                if (num2 - 1 < 0)
                    num1 -= 3;
                else {
                    num1--;
                    num2--;
                }
            }
            if (num1 < 0 || num2 < 0)
                return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> a = { 5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5 };
    cout<<s.lemonadeChange(a);
}