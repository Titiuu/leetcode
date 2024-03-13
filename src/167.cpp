#include "head.h"

class Solution { // 暴力：部分利用有序
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++) {
            if (numbers[i] + numbers[numbers.size() - 1] < target)
                continue;    
            for (int j = i + 1; j < numbers.size(); j++) {
                if (numbers[i] + numbers[j] == target)
                    return { i + 1,j + 1 };
                if (numbers[i] + numbers[j] > target)
                    break;
            }
        }
        return { -1,-1 };
    }
};

class Solution1 { //双指针
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            if (numbers[i] + numbers[j] > target) {
                j--;
            }
            if (numbers[i] + numbers[j] < target) {
                i++;
            }
            if (numbers[i] + numbers[j] == target) {
                return { i,j };
            }
        }
        return { -1,-1 };
    }
};

class Solution1 { //双指针 + 二分
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            int m = (i + j) / 2;
            if (numbers[i] + numbers[m] > target) {
                j = m;
            }
            if (numbers[m] + numbers[j] < target) {
                i = m - 1;
            }
            if (numbers[i] + numbers[j] > target) {
                j--;
            }
            if (numbers[i] + numbers[j] < target) {
                i++;
            }
            if (numbers[i] + numbers[j] == target) {
                return { i+1,j+1 };
            }
        }
        return { -1,-1 };
    }
};