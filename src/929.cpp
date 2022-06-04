#include "head.h"

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> res;
        for (auto& e : emails) {
            string temp;
            int flag = 0;
            for (int i = 0; i < e.size();i++) {
                if (flag == 0) {
                    if (e[i] == '.')continue;
                    if (e[i] == '+') {
                        while (e[i] != '@') {
                            i++;
                        }
                        flag++;
                    }
                    if (e[i] == '@') {
                        flag++;
                    }
                }
                temp.push_back(e[i]);
            }
            res.insert(temp);
        }
        return res.size();
    }
};

int main() {
    Solution S;
    vector<string> s = { "test.email+alex@leetcode.com", "test.email@leetcode.com" };
    S.numUniqueEmails(s);
}