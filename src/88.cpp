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