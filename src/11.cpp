#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    void quickSort(int left, int right, vector<int>& arr) {
        if (left >= right) //递归边界条件
            return;
        if (left < 0 || right >= arr.size())
        {
            cout << "error args! array bound." << endl;
            return;
        } //非法输入判断,防止数组越界
        int i, j, base, temp;
        i = left, j = right;
        base = arr[left]; //取最左边的数为基准数
        while (i < j)
        {
            while (arr[j] <= base && i < j)
                j--;
            while (arr[i] >= base && i < j)
                i++;
            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        //基准数归位
        arr[left] = arr[i];
        arr[i] = base;
        quickSort(left, i - 1, arr);  //递归左边
        quickSort(i + 1, right, arr); //递归右边
    }//快排，一开始的想法还是要排序
    int maxArea(vector<int>& height) {
        int res = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j)
        {
            int area = (j - i) * min(height[i], height[j]);
            if(area > res)
                res = area;
            if (height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return res;
    }
};

class Solution1 {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int res = 0;
        while (i < j) {
            res = max(res, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return res;
    }
};

int main()
{
    Solution S;
    vector<int> a={1,2,3,4,5,6};
}