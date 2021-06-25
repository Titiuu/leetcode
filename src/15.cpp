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

int main()
{
    Solution S;
    vector<int> l = {3,0,-2,-1,1,2};
    vector<vector<int>> a = S.threeSum(l);
    for(auto i:a)
    {
        for (auto j:i)
        {
            cout<<j<<',';
        }
    }
}