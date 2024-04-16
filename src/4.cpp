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


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        // n1 <= n2
        int k = n1 + ((n2-n1+1)>>1);
        int l = 0, r = n1;
        while(l < r) {
            int mid = l + ((r-l+1)>>1);
            if (nums1[mid - 1] > nums2[k - mid])
                r = mid - 1;
            else l = mid;
        }
        //l是中位线在第一个数组中左侧的位置
        //k-l是中位线在第二个数组中左侧的位置
        
        int leftMax1 = l==0 ? INT_MIN : nums1[l-1];
        int rightMin1 = l==n1 ? INT_MAX : nums1[l];
        int leftMax2 = k-l==0 ? INT_MIN : nums2[k-l-1];
        int rightMin2 = k-l==n2 ? INT_MAX : nums2[k-l];

        int t = max(leftMax1, leftMax2);
        if((n1+n2)%2 == 1) return (double)t;
        return (double)(t+min(rightMin1,rightMin2))/2.0;
    }
};
int main()
{
    vector<int> nums1={}, nums2={1};
    Solution S;
    cout << S.findMedianSortedArrays(nums1, nums2);
}