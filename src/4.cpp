#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        vector<int> nums;
        while(i < nums1.size() && j < nums2.size()){
            if (nums1[i] < nums2[j])
            {
                nums.push_back(nums1[i]);
                i++;
            }
            else{
                nums.push_back(nums2[j]);
                j++;
            }
        }
        if(i < nums1.size()){
            for (size_t k = i; k < nums1.size(); k++)
                nums.push_back(nums1[k]);
        }
        if(j < nums2.size()){
            for (size_t k = j; k < nums2.size(); k++)
                nums.push_back(nums2[k]);
        }
        if (nums.size() % 2 == 0)
            return (double)((nums[nums.size() / 2]) + (nums[nums.size() / 2 - 1])) / 2;
        else
            return (double)nums[(nums.size() - 1) / 2];
    }
};

int main()
{
    vector<int> nums1={}, nums2={1};
    Solution S;
    cout << S.findMedianSortedArrays(nums1, nums2);
}