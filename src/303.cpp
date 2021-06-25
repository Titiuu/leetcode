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

class NumArray {
private:
    //vector<int> nums;
    vector<int> sums;

public:
    NumArray(vector<int>& nums) {
        //this->nums = nums;
        sums.push_back(0);
        for (size_t i = 1; i < nums.size() + 1; i++)
        {
            sums.push_back(sums[i-1] + nums[i-1]);
        }
    }
    
    int sumRange(int i, int j) {
        return sums[j+1] - sums[i];
    }
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray* obj = new NumArray(nums);
    cout << obj->sumRange(0, 5);
}