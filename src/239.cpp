#include "head.h"

class Solution1 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        auto comp = [](const int& lhs, const int& rhs){
            return lhs > rhs;
        };
        vector<int> res;
        map<int, int, decltype(comp)> mp(comp);
        for(int i = 0; i < k; i++){
            mp[nums[i]]++;
        }
        res.push_back((*mp.begin()).first);
        for(int i = k; i < nums.size(); i++){
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0)
                mp.erase(nums[i-k]);
            mp[nums[i]]++;
            res.push_back((*mp.begin()).first);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        vector<int> ans = {nums[q.front()]};
        for (int i = k; i < n; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            while (q.front() <= i - k) {
                q.pop_front();
            }
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
    s.maxSlidingWindow(nums, 3);
}