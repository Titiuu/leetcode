#include "head.h"

class Solution {
public:
    string convertToBase7(int num) {
        string res;
        if (num > 0) {
            while (num * 7 >= 7) {
                res.insert(0, to_string(num % 7));
                num /= 7;
            }
            return res;
        }
        else if (num < 0) {
            int t = num * -1;
            while (t * 7 >= 7) {
                res.insert(0, to_string(t % 7));
                t /= 7;
            }
            res.insert(0, "-");
            return res;
        }
        else
            return "0";
    }
};