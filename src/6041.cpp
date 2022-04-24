#include "head.h"

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& arrs) {
        vector<int> ret;
        set<int> myset[arrs.size()];
        for (int i = 0; i < arrs.size(); i++) {
            for (int j = 0; j < arrs[i].size(); j++) {
                myset[i].insert(arrs[i][j]);
            }
        }

        for (int i = 0; i < arrs[0].size(); i++) {
            bool tmp = true;
            for (int j = 1; j < arrs.size(); j++) {
                if ((myset[j].find(arrs[0][i])) == myset[j].end()) {
                    tmp = false;
                    break;
                }
            }
            if (tmp == true) {
                ret.emplace_back(arrs[0][i]);
            }
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};