#include "head.h"

class Solution {
private:
    void quickSort(vector<int>& nums, int p, int q) {
        if (p >= q)
            return;
        int temp = nums[p];
        int i = p + 1, j = q;
        while (i <= j) {
            while (i <= q && nums[i] <= temp) {
                i++;
            }
            while (j >= p && nums[j] >= temp) {
                j--;
            }
            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[p], nums[i - 1]);
        quickSort(nums, p, i - 2);
        quickSort(nums, i, q);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main() {
    vector<int> a { 5,1,1,2,0,0 };
    Solution s;
    s.sortArray(a);
}