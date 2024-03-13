#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <regex>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3) return ans;
        sort(nums.begin(), nums.end());
        int temp1 = nums[0]-1, temp2 = nums[0]-1, temp3 = nums[nums.size()-1] + 1;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (temp1 != nums[i])
            {
                size_t j = i + 1, k = nums.size() - 1;
                while (j < k)
                {
                    if (temp2 != nums[j] && temp3 != nums[k])
                    {
                        if (nums[i] + nums[j] + nums[k] == 0)
                        {
                            ans.push_back({nums[i], nums[j], nums[k]});
                            temp2 = nums[j];
                            j++;
                        }
                        else if (nums[i] + nums[j] + nums[k] > 0)
                        {
                            temp3 = nums[k];
                            k--;
                        }
                        else
                        {
                            temp2 = nums[j];
                            j++;
                        }
                    }
                    else if (temp2 == nums[j] && temp3 != nums[k])
                    {
                        temp2 = nums[j];
                        j++;
                    }
                        
                    else if (temp2 != nums[j] && temp3 == nums[k])
                    {
                        temp3 = nums[k];
                        k--;
                    }
                        
                    else
                    {
                        temp2 = nums[j];
                        temp3 = nums[k];
                        j++;
                        k--;
                    }
                }
            }
            temp1 = nums[i];
            temp2 = nums[0]-1;
            temp3 = nums[nums.size()-1] + 1;
        }
        return ans;
    }
};

class Solution1 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int pre = 1e6;
        for (int k = 0; k < nums.size() - 2; k++) {
            while (k < nums.size() - 2 && nums[k] == pre) k++;
            if (k == nums.size() - 2) break;
            int target = -1 * nums[k];
            if (nums[k] + nums[k + 1] + nums[k + 2] > 0)
                break;
            int i = k + 1, j = nums.size() - 1;
            while (i < j) {
                int m = (i + j) / 2;
                if (nums[i] + nums[m] > target) {
                    j = m;
                }
                if (nums[m] + nums[j] < target) {
                    i = m;
                }
                if (nums[i] + nums[j] > target) {
                    j--;
                }
                if (nums[i] + nums[j] < target) {
                    i++;
                }
                if (nums[i] + nums[j] == target) {
                    if (i != j && i != k && j != k)
                        res.push_back({ nums[k],nums[i],nums[j] });
                    int left = nums[i], right = nums[j];
                    while (i + 1 < nums.size() && nums[i + 1] == left) i++;
                    while (j > 0 && nums[j - 1] == right) j--;
                    if (i+1>=j-1) break;
                    i = i + 1;
                    j = j - 1;
                }
            }
            pre = nums[k];
        }
        return res;
    }
};

int main()
{
    Solution1 S;
    vector<int> l = {0,0,0,0};
    vector<vector<int>> a = S.threeSum(l);
    for(auto i:a)
    {
        for (auto j:i)
        {
            cout<<j<<',';
        }
    }
    return 0;
}