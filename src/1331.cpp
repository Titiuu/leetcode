#include "head.h"

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.size() == 0){
            return arr;
        }
        if (arr.size() == 1){
            arr[0] = 1;
            return arr;
        }
        vector<int> clone = arr;
        //排序
        sort(clone.begin(), clone.end());
        map<int, int> map;
        int num = clone[0];
        int index = 1;
        map[clone[0]] = index;
        for (int i = 1; i < clone.size() ; i++) {
            if (num != clone[i]){
                map[clone[i]] = ++index;
                num = clone[i];
            }
        }
        //替换num
        for (int i = 0; i < arr.size() ; i++) {
            arr[i] = map[arr[i]];
        }
        return arr;
    }
};