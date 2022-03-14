#include "head.h"

class Solution {  //暴力解
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int n1 = list1.size(), n2 = list2.size();
        vector<string> res;
        int minIndex = 2000;
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (i + j <= minIndex) {
                    if (list1[i] == list2[j]) {
                        if (i + j < minIndex) {
                            minIndex = i + j;
                            res.clear();
                            res.emplace_back(list1[i]);
                        }
                        else if (i + j == minIndex) {
                            res.emplace_back(list1[i]);
                        }
                    }
                }
            }
        }
        return res;
    }
};

class Solution {  //hash
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int n1 = list1.size(), n2 = list2.size();
        vector<string> res;
        int minIndex = 2000;
        unordered_map<string, int> hash;
        for (int i = 0; i < n2; i++) {
            pair<string, int> t = { list2[i], i };
            hash.emplace(t);
            // hash[list2[i]] = i;
        }
        for (int i = 0; i < n1; i++) {
            auto it = hash.find(list1[i]);
            if (it != hash.end()) {
                int index = i + it->second;
                if (index < minIndex) {
                    minIndex = index;
                    res.clear();
                    res.emplace_back(list1[i]);
                }
                else if (index == minIndex) {
                    res.emplace_back(list1[i]);
                }
            }
        }
        return res;
    }
};