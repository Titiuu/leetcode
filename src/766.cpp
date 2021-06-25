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
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(), columns = matrix[0].size();
        for (int i = 0; i < rows; i++)
        {
            int j = i, k = 0, temp = matrix[i][0];
            while(j < rows && k < columns)
            {
                if(temp != matrix[j][k])    return false;
                j++;
                k++;
            }
        }
        for (int i = 0; i < columns; i++)
        {
            int j = 0, k = i, temp = matrix[0][i];
            while(j < rows && k < columns)
            {
                if(temp != matrix[j][k])    return false;
                j++;
                k++;
            }
        }
        return true;
    }
};