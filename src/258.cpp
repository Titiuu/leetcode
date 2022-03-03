#include "head.h"

class Solution {
private:
    int getSum(int num) {
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
public:
    int addDigits(int num) {
        return num > 9 ? addDigits(getSum(num)) : num;
    }
};