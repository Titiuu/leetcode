#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <regex>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int temp1 = nums[0]-1, temp2 = nums[0]-1, temp3 = nums[nums.size()-1] + 1;
        int ans = 999999, num = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (temp1 != nums[i])
            {
                size_t j = i + 1, k = nums.size() - 1;
                while (j < k)
                {
                    if (temp2 != nums[j] && temp3 != nums[k])
                    {
                        num = nums[i] + nums[j] + nums[k];
                        if ( num == target)
                        {
                            return num;
                        }
                        else if (num > target)
                        {
                            if(num - target < abs(ans)) ans = num - target;
                            temp3 = nums[k];
                            k--;
                        }
                        else
                        {
                            if(target - num < abs(ans)) ans = num - target;
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
        return ans + target;
    }
};

int main()
{
    Solution S;
    vector<int> l = {-1,2,1,-4};
    cout<<S.threeSumClosest(l, 1);
}