#include "head.h"

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> hashmap;
        for (auto task : tasks) {
            if (hashmap.count(task) == 0) {
                hashmap[task] = 1;
            }
            else
                hashmap[task]++;
        }
        int res = 0;
        for (auto p : hashmap) {
            if (p.second == 1)
                return -1;
            if (p.second % 3 == 1 || p.second % 3 == 2)
                res += p.second / 3 + 1;
            else
                res += p.second / 3;
        }
        return res;
    }
};