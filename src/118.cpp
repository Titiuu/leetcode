#include "head.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> first = { 1 };
        vector<int> second = { 1, 1 };
        vector<vector<int>> res;
        if (numRows == 1) {
            res.push_back(first);
            return res;
        }
        if (numRows == 2) {
            res.push_back(first);
            res.push_back(second);
            return res;
        }
        res.push_back(first);
        res.push_back(second);
        for (int i = 2; i < numRows; i++) {
            vector<int> temp = {1};
            for (int j = 0; j < i - 1; j++) {
                temp.push_back(second[j] + second[j + 1]);
            }
            temp.push_back(1);
            res.push_back(temp);
            second = temp;
        }
        return res;
    }
};