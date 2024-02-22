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

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m==0) {
            nums1 = nums2;
            return;
        }
        if (n==0) {
            return;
        }   
        int k = nums1.size(), i, j;
        for (i = m - 1, j = n - 1; i >= 0 && j >= 0;) {
            if (nums1[i] > nums2[j]) {
                nums1[k-1] = nums1[i];
                k--;
                i--;
            }
            else {
                nums1[k-1] = nums2[j];
                k--;
                j--;
            }
        }
        if (j > 0) {
            for (; j >= 0; j--)
            {
                nums1[k-1] = nums2[j];
                k--;
            }
        }
    }
};

class Solution1 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        if (n == 0)
            return;
        int i = nums1.size() - 1, j = nums2.size() - 1, k = m - 1;
        while (i >= 0) {
            if (nums1[k] > nums2[j]) {
                nums1[i] = nums1[k];
                k--;
                if (k < 0) {
                    i--;
                    while (i >= 0) {
                        nums1[i] = nums2[j];
                        i--;
                        j--;
                    }
                    return;
                }
            }
            else {
                nums1[i] = nums2[j];
                j--;
                if (j < 0)
                    return;
            }
            i--;
        }
    }
};

int main() {
    Solution1 s;
    vector<int> nums1 = {4,5,6,0,0,0}, nums2 = {1,2,3};
    s.merge(nums1, 3, nums2, 3);
    for (size_t i = 0; i < nums1.size(); i++) {
        cout << nums1[i];
    }
}