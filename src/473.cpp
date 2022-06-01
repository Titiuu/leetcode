#include "head.h"

class Solution {
private:
    bool dfs(int index, vector<int>& matchsticks, vector<int>& lens) {
        if (index == matchsticks.size()) {
            return true;
        }
        for (int i = 0; i < lens.size(); i++) {
            lens[i] += matchsticks[index];
            if (lens[i] <= len) {
                if (dfs(index + 1, matchsticks, lens))
                    return true;
            }
            lens[i] -= matchsticks[index];
        }
        return false;
    }
public:
    int len = 0;
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0)
            return false;
        len = sum / 4;
        sort(matchsticks.begin(), matchsticks.end(), [](int a, int b) {
            return a > b;
            });
        vector<int> lens(4);
        return dfs(0, matchsticks, lens);
    }
};

int main() {
    Solution S;
    vector<int> matchsticks = {5,5,5,5,4,4,4,4,3,3,3,3};
    S.makesquare(matchsticks);
}