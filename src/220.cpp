#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <regex>
#include <cmath>
#include <numeric>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {//边界判定很烦要统一简化，然后滑动窗口排序减少复杂度
        int n = nums.size();
        if (n < 2)
            return false;
        if (k == 0)
            return false;
        if (k < n - 1) {
            for (int i = 0; i < n - k; i++)
            {
                for (int j = i + 1; j <= i + k; j++)
                {
                    if (abs((long)nums[i] - (long)nums[j]) <= t)
                        return true;
                }
            }
            for (int i = n - k; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (abs((long)nums[i] - (long)nums[j]) <= t)
                        return true;
                }
            }
        }
        else {
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (abs((long)nums[i] - (long)nums[j]) <= t)
                        return true;
                }
            }
        }
        return false;
    }
};


class Solution1 { //桶排序
public:
    long size;
        bool containsNearbyAlmostDuplicate(vector <int> & nums, int k, int t) {
        int n = nums.size();
        map<long, long> m;
        size = t + 1L;
        for (int i = 0; i < n; i++) {
            long u = nums[i] * 1L;
            long idx = getIdx(u);
            // 目标桶已存在（桶不为空），说明前面已有 [u - t, u + t] 范围的数字
            if (m.find(idx) != m.end()) return true;
            // 检查相邻的桶
            long l = idx - 1, r = idx + 1;
            if (m.find(l) != m.end() && abs(u - m[l]) <= t) return true;
            if (m.find(r) != m.end() && abs(u - m[r]) <= t) return true;
            // 建立目标桶
            m.insert({idx, u});
            // 移除下标范围不在 [max(0, i - k), i) 内的桶
            if (i >= k) m.erase(getIdx(nums[i - k]));
        }
        return false;
    }
    long getIdx(long u) {
        return u >= 0 ? u / size : (u + 1) / size - 1;
    }
};

class Solution2 { //排序，遍历
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<long,long>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back(make_pair(nums[i],i));
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                if(abs(v[i].first-v[j].first)<=t&&abs(v[i].second-v[j].second)<=k){
                    return true;
                }
                if(abs(v[i].first-v[j].first)>t){
                    break;
                }
            }
        }
        return false;
    }
};