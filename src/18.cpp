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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size()<4) return res;
        sort(nums.begin(), nums.end());
        int temp1, temp2, temp3, temp4;
        temp1 = temp2 = temp3 = temp4 = nums[0]-1;
        int num = 0;
        for (size_t h = 0; h < nums.size(); h++) {
            if (temp4 != nums[h]) {
                for (size_t i = h + 1; i < nums.size(); i++)
                {
                    if (temp1 != nums[i])
                    {
                        size_t j = i + 1, k = nums.size() - 1;
                        while (j < k)
                        {
                            if (temp2 != nums[j] && temp3 != nums[k])
                            {
                                num = nums[i] + nums[j] + nums[k] + nums[h];
                                if (num == target)
                                {
                                    res.push_back({nums[h], nums[i], nums[j], nums[k]});
                                    temp2 = nums[j];
                                    j++;
                                }
                                else if (num > target)
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
                    temp2 = temp3 = nums[0] - 1;
                }
            }
            temp4 = nums[h];
            temp1 = temp2 = temp3 = nums[0] - 1;
        }
        return res;
    }
};

int main()
{
    Solution S;
    vector<int> l = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> a = S.fourSum(l, 0);
    for(auto i: a){
        for (auto j:i)
        {
            cout<<j<<',';
        }
        cout<<" ";
    }
}