#include "head.h"

class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string t;
            for (int i = 0; i < s.size(); i += k) {
                string temp;
                if (i + k > s.size())
                    temp = to_string(accumulate(s.begin() + i, s.end(), 0) - '0' * (s.size() - i));
                else
                    temp = to_string(accumulate(s.begin() + i, s.begin() + i + k, 0) - '0' * k);
                t.append(temp);
            }
            s = t;
        }
        return s;
    }
};

int main() {
    Solution S;
    cout << S.digitSum("11111222223", 3);
    
    return 0;
}